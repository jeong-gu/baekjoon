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
    process_raw *process;//현재 프로세스
    int ref_idx;        // 현재 참조 인덱스
    int page_fault_num; // 누적 페이지 폴트 수
    int l1_frame;       //L1 페이지 테이블이 위치한 PAS에서 프레임 번호 (L1 PageTable의 위치)
}pm; //process manager

unsigned char *pas; //물리 메모리를 흉내 내는 시뮬레이션용 배열
pm *process_arr;        //process manager
int free_frame=0;    //할당 가능한 프레임

void init_pas(){
    pas =(unsigned char *)malloc(PAS_SIZE);     //실제 물리 메모리 할당
    process_arr=(pm *)malloc(MAX_PROCESSES*sizeof(pm));//프로세스 개수만큼 메모리에 할당
    process_arr=(pm *)malloc(MAX_PROCESSES*sizeof(pm));// 0(NULL)로 초기화하여 후에 탐색에 활용(0(NULL)이 될 때까지 탐색)
    memset(process_arr,0,MAX_PROCESSES*sizeof(pm));
}

void init_pagetable(int pid){
    //pas의 할당가능한 free_frame을 L1 페이지 테이블용으로 사용
    pte *l1=(pte *)&pas[free_frame*PAGESIZE];

    // 1프레임 안에 들어갈 수 있는 PTE 개수 계산 (예: 32 / 4 = 8개)
    int l1_pte_count=PAGESIZE/PTE_SIZE;

    for(int i=0;i<l1_pte_count;i++){
        l1[i].frame=0;
        l1[i].vflag=PAGE_INVALID;
        l1[i].ref=0;
        l1[i].pad=0;
    }

    //	L1 테이블이 PAS 내 어디 있는지 계산 불가능 → 추적 필요
    //process_arr로 추적
    process_arr[pid].process->pid=pid;
    process_arr[pid].ref_idx=0;
    process_arr[pid].page_fault_num=0;
    process_arr[pid].l1_frame=free_frame;
    free_frame++;
}
//가변 변수 조정((PAGESIZE(4B), PAS_FRAMES(4B), VAS_PAGES(4B))
void settings(){
    unsigned char dummy[12];//총 12바이트: PAGESIZE(4), PAS_FRAMES(4), VAS_PAGES(4)
    //fread()를 통해 한번에 덩어리로 3개의 정보를 read
    if(fread(dummy,sizeof(dummy),1,stdin)!=1){
        return;
    }

    PAGESIZE=*(int *)&dummy[0];
    PAS_FRAMES=*(int *)&dummy[4];
    VAS_PAGES=*(int *)&dummy[8];

    //받은 세 변수 값을 토대로 파생되는 변수
    PAS_SIZE=PAGESIZE*PAS_FRAMES;//Physical Address Space의 크기 //메모리 크기 
    VAS_SIZE=PAGESIZE*VAS_PAGES;//Virtual Address Space의 크기 //프로세스가 쓰는 메모리 크기
    PAGETABLE_FRAMES=(VAS_PAGES*PTE_SIZE)/PAGESIZE;//페이지 테이블 전체를 담기 위해 필요한 프레임 수
}
void process_load(){
    process_raw *tmp;
    while(1){
        tmp=malloc(sizeof(*tmp));//새 프로세스 구조체 할당
        
         //pid를 읽어오고 실패시 break
        if(fread(&tmp->pid,sizeof(int),1,stdin)!=1){
            free(tmp);
            break;
        }
         //ref_len을 읽어오고 실패시 break;
        if(fread(&tmp->ref_len,sizeof(int),1,stdin)!=1){
            free(tmp);
            break;
        } //max_processes(10)보다 많은 프로세스가 입력되거나 max_references보다 더 많은 referece가 들어 오려고 하면 continue
        if(tmp->pid>=MAX_PROCESSES||tmp->ref_len>MAX_REFERENCES){
            free(tmp);
            break;
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
    int L1_ENTRY_NUM=PAGESIZE/PTE_SIZE; //L1 페이지 엔트리 수
    int L2_ENTRY_NUM=L1_ENTRY_NUM;      // L2 테이블도 동일한 엔트리 수
    while(1){
        bool flag=true;  //모든 프로세스의 references가 끝났는지 확인
        for(int i=0;i<MAX_PROCESSES;i++){
            if(process_arr[i].process==NULL) continue;  //프로세스가 없으면 무시

            process_raw *cur=process_arr[i].process;  //처리할 프로세스
            int idx=process_arr[i].ref_idx;         //다음 reference

            if(idx==cur->ref_len) continue; //reference가 끝에 도달하면 종료
            flag=false;
            
            unsigned char page=cur->references[idx]; //0~255 virtual page번호

            //L1과 L2의 인덱스 -> 구하는 방식은 과제 명세에 따라
            int l1_idx=page/L2_ENTRY_NUM;           
            int l2_idx=page%L2_ENTRY_NUM;           

            // L1 Page Table 주소 계산 (이 프로세스의 L1 프레임 기반)
            pte *l1_pt=(pte *)&pas[process_arr[i].l1_frame*PAGESIZE]; 
            
            //L1 PTE check
            if(l1_pt[l1_idx].vflag==PAGE_INVALID){//page fault 발생
                if(free_frame>=PAS_FRAMES){
                    printf("Out of memory!!\n");
                    return;
                }
                l1_pt[l1_idx].frame=free_frame++;
                l1_pt[l1_idx].vflag=PAGE_VALID;
                //pt[page].ref=1;
                //referece 안셈
                process_arr[i].page_fault_num++;
            }
            //L1 PTE CHECK 이후 L2 프레임을 할당한 후 바로 접근
            //L2 Page Table 접근 
            pte *l2_pt=(pte *)&pas[l1_pt[l1_idx].frame*PAGESIZE];

            if(l2_pt[l2_idx].vflag==PAGE_INVALID){//page fault
                if(free_frame>=PAS_FRAMES){
                    printf("Out of memory!!\n");
                    return;
                }
                l2_pt[l2_idx].frame=free_frame++;   //3-1과 같은 매커니즘
                l2_pt[l2_idx].vflag=PAGE_VALID;
                l2_pt[l2_idx].ref=1;
                process_arr[i].page_fault_num++;
            }
            else{   //page fault 발생 x -> 참조만
                l2_pt[l2_idx].ref++;
            }
            process_arr[i].ref_idx++;
        }
        if(flag) break;
    }
}

void print_total(){
     // L1/L2 테이블 엔트리 수: 한 프레임 안에 몇 개의 페이지 테이블 엔트리가 들어가는지
    int L1_ENTRY_NUM=PAGESIZE/PTE_SIZE;
    int L2_ENTRY_NUM=L1_ENTRY_NUM;

    int total_allocated_frame=0; //전체 할당된 프레임 수
    int total_page_falut=0;      //전체 pagefault 수
    int total_references=0;         //전체 references 수
    //모든 프로세스 순회
    for(int i=0;i<MAX_PROCESSES;i++){
        if(process_arr[i].process==NULL) continue;  //해당 프로세스가 없으면 continue

         //개별 프로세스의 pagefault와 references num
        process_raw *tmp=process_arr[i].process;
        int page_fault=process_arr[i].page_fault_num;
        int references_num=process_arr[i].ref_idx;
        int allocated_frames=page_fault+1; //allocated_frames : L1 frames+ L2 frames -> 
        
        //수식을 통해 할당된 프레임 수 유도.
        //(한 페이지 테이블의 프레임 수) allocated_frames=page_fault+1; **
        printf("** Process %03d: Allocated Frames=%03d PageFaults/References=%03d/%03d\n",
        tmp->pid,allocated_frames,page_fault,references_num);

        pte *l1=(pte*)&pas[process_arr[i].l1_frame*PAGESIZE];
        for(int j=0;j<L1_ENTRY_NUM;j++){
            if(l1[j].vflag==PAGE_VALID){
                // L1 페이지 테이블에 유효한 항목이 있을 때 출력
                // j번째 엔트리는 l1[j].frame을 L2 테이블로 사용함
                printf("(L1PT) %03d -> %03d\n",j,l1[j].frame);
                pte *l2=(pte *)&pas[l1[j].frame*PAGESIZE];
                for(int k=0;k<L2_ENTRY_NUM;k++){
                    if(l2[k].vflag==PAGE_VALID){
                        int vpn=j*L2_ENTRY_NUM+k;// 원래의 virtual page 번호
                        // L2 엔트리 출력: 어느 물리 프레임에 매핑되었고 몇 번 참조되었는지
                        printf("(L2PT) %03d -> %03d REF=%03d\n",vpn,l2[k].frame,l2[k].ref);
                    }
                }
            }
        }

        total_allocated_frame+=(allocated_frames);
        total_page_falut+=page_fault;
        total_references+=references_num;
    }
    printf("Total: Allocated Frames=%03d Page Faults/References=%03d/%03d\n",
    total_allocated_frame,total_page_falut,total_references);
}

void free_mem(){
    for(int i=0;i<MAX_PROCESSES;i++){
        if(process_arr[i].process==NULL) continue;
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