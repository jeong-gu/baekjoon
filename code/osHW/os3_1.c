#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PTE_SIZE (4) //Page Table Entry 크기 (항상 4바이트)

//가변 변수
int PAGESIZE;
int PAS_FRAMES;
int VAS_PAGES;
int PAS_SIZE;
int VAS_SIZE;
int PAGETABLE_FRAMES;

#define PAGE_INVALID (0)

#define PAGE_VALID (1)

#define MAX_REFERENCES (256)
#define MAX_PROCESSES (10)

typedef struct{
    unsigned char frame; //allocated frame
    unsigned char vflag; //valid-invalid bit
    unsigned char ref; //reference bit
    unsigned char pad; //padding
} pte; // Page Table Entry (total 4 Bytes, always)

typedef struct{
    int pid;
    int ref_len; //Less than 255
    unsigned char *references;
} process_raw;

typedef struct{
    process_raw *process; //현재 프로세스
    int ref_idx;        // 현재 참조 인덱스
    int page_fault_num;  // 누적 페이지 폴트 수
}pm; //process manager

unsigned char *pas; //물리 메모리를 흉내 내는 시뮬레이션용 배열
pm *process_arr;    //process manager
int free_frame=0;   //할당 가능한 프레임

void init_pas(){
    pas =(unsigned char *)malloc(PAS_SIZE); //실제 물리 메모리 할당
    process_arr=(pm *)malloc(MAX_PROCESSES*sizeof(pm)); //프로세스 개수만큼 메모리에 할당
    memset(process_arr,0,MAX_PROCESSES*sizeof(pm)); // 0(NULL)로 초기화하여 후에 탐색에 활용(0(NULL)이 될 때까지 탐색)
}

void init_pagetable(int pid){
    //pas의 할당가능한 free_frame을 pte로 할당. 
    pte *cur=(pte *)&pas[free_frame*PAGESIZE];

    for(int i=0;i<VAS_PAGES;i++){
        cur[i].frame=0;
        cur[i].vflag=PAGE_INVALID;
        cur[i].ref=0;
        cur[i].pad=0;
    }
    //다음 할당가능한 free_frame으로 
    free_frame+=PAGETABLE_FRAMES;
}

//가변 변수 조정((PAGESIZE(4B), PAS_FRAMES(4B), VAS_PAGES(4B))
void settings(){
    unsigned char dummy[12]; //총 12바이트: PAGESIZE(4), PAS_FRAMES(4), VAS_PAGES(4)
    //fread()를 통해 한번에 덩어리로 3개의 정보를 read
    if(fread(dummy,sizeof(dummy),1,stdin)!=1){
        return;
    }

    PAGESIZE=*(int *)&dummy[0];
    PAS_FRAMES=*(int *)&dummy[4];
    VAS_PAGES=*(int *)&dummy[8];

    //받은 세 변수 값을 토대로 파생되는 변수
    PAS_SIZE=PAGESIZE*PAS_FRAMES;//Physical Address Space의 크기 //메모리 크기 
    VAS_SIZE=PAGESIZE*VAS_PAGES; //Virtual Address Space의 크기 //프로세스가 쓰는 메모리 크기
    PAGETABLE_FRAMES=(VAS_PAGES*PTE_SIZE)/PAGESIZE; //페이지 테이블 전체를 담기 위해 필요한 프레임 수
}
void process_load(){
    process_raw *tmp;
    while(1){
        tmp=malloc(sizeof(*tmp)); //새 프로세스 구조체 할당 

        //pid를 읽어오고 실패시 break
        if(fread(&tmp->pid,sizeof(int),1,stdin)!=1){
            free(tmp);
            break;
        }
        //ref_len을 읽어오고 실패시 break;
        if(fread(&tmp->ref_len,sizeof(int),1,stdin)!=1){
            free(tmp);
            break;
        }
        //max_processes(10)보다 많은 프로세스가 입력되거나 max_references보다 더 많은 referece가 들어 오려고 하면 continue
        if(tmp->pid>=MAX_PROCESSES||tmp->ref_len>MAX_REFERENCES){
            free(tmp);
            continue;
        }
        // ref_len만큼의 reference전부를 한번에 받아옴
        tmp->references=malloc(tmp->ref_len);
        if(fread(tmp->references,sizeof(unsigned char),tmp->ref_len,stdin)!=(size_t)tmp->ref_len){
            free(tmp->references);
            free(tmp);
            break;
        }
        
        
        //프로세스의 정보를 process_arr배열에 추가
        process_arr[tmp->pid].process=tmp;
        process_arr[tmp->pid].ref_idx=0;
        process_arr[tmp->pid].page_fault_num=0;
        
        init_pagetable(tmp->pid);   //프로세스의 pageTable을 초기화
    }
    
}


void oper(){
    while(1){
        bool flag=true; //모든 프로세스의 references가 끝났는지 확인

        for(int i=0;i<MAX_PROCESSES;i++){
            if(process_arr[i].process==NULL) continue; //프로세스가 없으면 무시

            process_raw *cur=process_arr[i].process;    //처리할 프로세스
            int idx=process_arr[i].ref_idx; //다음 reference

            if(idx==cur->ref_len) continue; //reference가 끝에 도달하면 종료
            flag=false;

            pte *pt=(pte *)&pas[cur->pid*PAGETABLE_FRAMES*PAGESIZE]; //이 프로세스의 pageTable위치 계산
            unsigned char page=cur->references[idx]; //0~255 virtual page번호
            
            //page fault 발생
            if(pt[page].vflag==PAGE_INVALID){
                if(free_frame>=PAS_FRAMES){ //남은 프레임이 없음. 처리 종료
                    printf("Out of memory!!\n");    
                    return;
                }
                pt[page].frame=free_frame++; //free_frame을 썼으니 다음으로 +1
                pt[page].vflag=PAGE_VALID; //valid 표시
                pt[page].ref=1; //reference 세기 시작
                process_arr[i].page_fault_num++;
            }
            else{   //page fault 발생 x -> 참조만
                pt[page].ref++;
            }
            process_arr[i].ref_idx++;
        }
        if(flag) break;
    }
}

void print_total(){
    int total_allocated_frame=0;    //전체 할당된 프레임 수
    int total_page_falut=0;         //전체 pagefault 수
    int total_references=0;         //전체 references 수
    for(int i=0;i<MAX_PROCESSES;i++){
        if(process_arr[i].process==NULL) continue;  //해당 프로세스가 없으면 continue

        //개별 프로세스의 pagefault와 references num
        process_raw *tmp=process_arr[i].process;
        int page_fault=process_arr[i].page_fault_num;
        int references_num=process_arr[i].ref_idx;

        //수식을 통해 할당된 프레임 수 유도. page_fault+pagetable_frames(한 페이지 테이블의 프레임 수)
        printf("** Process %03d: Allocated Frames=%03d PageFaults/References=%03d/%03d\n",
        tmp->pid,page_fault+PAGETABLE_FRAMES,page_fault,references_num);
        
        //pt는 이 프로세스의 pageTable 위치
        pte *pt=(pte*)&pas[tmp->pid*PAGETABLE_FRAMES*PAGESIZE];

        //virtual pages의 수만큼 순회. valid한 페이지만 ref한 프레임 출력
        for(int j=0;j<VAS_PAGES;j++){
            if(pt[j].vflag==PAGE_VALID){
                printf("%03d -> %03d REF=%03d\n",j,pt[j].frame,pt[j].ref);
            }
        }
        
        
        total_allocated_frame+=(page_fault+PAGETABLE_FRAMES);
        total_page_falut+=page_fault;
        total_references+=references_num;
    }

    printf("Total: Allocated Frames=%03d Page Faults/References=%03d/%03d\n",
    total_allocated_frame,total_page_falut,total_references);
}

void free_mem(){
    for(int i=0;i<MAX_PROCESSES;i++){
        if(process_arr[i].process==NULL) continue; //프로세스 순회

        free(process_arr[i].process->references);
        free(process_arr[i].process);
    }
    free(process_arr);
    free(pas);
}
int main(int argc,char *argv[]){
    settings(); 
    init_pas();    
    process_load();
    oper();
    print_total();
    free_mem();
    return 0;
}