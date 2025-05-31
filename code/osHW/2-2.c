#include "list.h"

//input tmp 구조
typedef struct{
    int pid;
    int arrival_time;
    int code_bytes;
} tmp;
//code tuple 집합 구조 
typedef struct{
    unsigned char opcode; //자료형 크기가 1 byte이므로 
    unsigned char length;
}code;

//프로세스 구조
typedef struct{
    int pid;
    int arrival_time;
    int code_bytes;
    code *operations;

    int pc; //program count
    int terminated;
    int loaded;
    int io_end_time;

    struct list_head job;
    struct list_head ready;
    struct list_head wait;
} process;

//CPU 구조
typedef struct{
    struct list_head ready_q;
    struct list_head wait_q;

    process *current;
    process *prev;
    int context_switch;
    int idle_time;
}CPU;

void process_load(struct list_head *job_q){
    tmp t;      //프로세스 정보 임시 저장
    process *p;  //프로세스 객체 포인터
    while(fread(&t, sizeof(tmp),1,stdin)==1){   //file입력
        p=malloc(sizeof(*p));   //객체 동적 할당

        //tmp에 임시 저장한 값 process에 입력
        p->pid=t.pid;
        p->arrival_time=t.arrival_time;
        p->code_bytes=t.code_bytes;

        //작업 전이므로 다 0
        p->pc=0;
        p->terminated=0;
        p->loaded=0;
        p->io_end_time=0;

        //리스트 헤드 초기화 (ready, wait는 추후 과제를 위해 만들어놓음), job리스트 헤드를 job_q에 추가 
        INIT_LIST_HEAD(&p->job);
        INIT_LIST_HEAD(&p->ready);
        INIT_LIST_HEAD(&p->wait);
        list_add_tail(&p->job,job_q);

        int iter=t.code_bytes/2;           //code_bytes는 4byte이고 code_tuple은 2byte이므로
        short ttmp;                         //code_tuple은 2byte이므로 2byte단위로 읽기 위해 short

        p->operations=malloc(sizeof(code)*iter); //code sturct가 iter개있으므로

        for(int i=0;i<iter;i++){       //code_tuple 개수
            if(fread(&ttmp,sizeof(short),1,stdin)==1){
                p->operations[i].opcode=ttmp&0xFF;      
                p->operations[i].length=(ttmp>>8)&0xFF;
            }
        }

        
    }
}
void free_process(struct list_head *job_q){
    process *cur,*next;
    list_for_each_entry_safe(cur,next,job_q,job){
        list_del(&cur->job);
        free(cur->operations);
        free(cur);
    }
}
//idle process 생성
process* make_idle(){
    process *idle=malloc(sizeof(*idle));
    idle->pid=100;
    idle->arrival_time=0;
    idle->code_bytes=2;
    
    idle->operations=malloc(sizeof(code)*1);
    //최대 크기 조정
    idle->operations[0].opcode=0xFF;
    idle->operations[0].length=255;

    idle->pc=0;
    idle->terminated=0;

    INIT_LIST_HEAD(&idle->job);
    INIT_LIST_HEAD(&idle->ready);
    INIT_LIST_HEAD(&idle->wait);

    return idle;
}
//ready Queue에 프로세스 로드
void ready_load(struct list_head *job_q,CPU *cpu, int clock,process *idle[]){
    process *p;
    process *tmp;
    list_for_each_entry_safe(p,tmp,job_q,job){
        if(p->arrival_time<=clock&&!p->loaded){
            
            //두 개의 cpu가 모두 context switching 중이라면 프로세스 로드 불가능
            if(cpu[0].context_switch>0&&cpu[1].context_switch>0){
                continue;
            }
            
            int len0=0; int len1=0;
            process *pos;
            //레디큐에 있는 프로세스 개수
            list_for_each_entry(pos,&cpu[0].ready_q,ready) len0++;
            list_for_each_entry(pos,&cpu[1].ready_q,ready) len1++;

            //cpu가 기본 idle이 아니라면 뭔가를 실행 중인 것이므로 가중
            if(cpu[0].current->pid!=100||!list_empty(&cpu[0].wait_q)) len0++;
            if(cpu[1].current->pid!=100||!list_empty(&cpu[1].wait_q)) len1++;

            int target_cpu;
            //프로세스가 덜 있는 곳에 load balancing 같다면 1번 프로세스에
            target_cpu=(len0<=len1)?0:1;
            
            printf("%04d CPU%d: Loaded PID: %03d\tArrival: %03d\tCodesize: %03d\n",
                clock, target_cpu + 1, p->pid, p->arrival_time, p->code_bytes);
            list_add_tail(&p->ready,&cpu[target_cpu].ready_q);
            p->loaded=1;
        }
    }
    //clock이 0이라면 기본 idle이 들어가는 것으로 간주 //실제로는 idle을 레디 큐에 넣지 않고 simulate
    if(clock==0){
        for(int i=0;i<2;i++){
            int cpu_id=i;
            printf("%04d CPU%d: Loaded PID: %03d\tArrival: %03d\tCodesize: %03d\n",clock,cpu_id+1,idle[cpu_id]->pid,idle[cpu_id]->arrival_time,idle[cpu_id]->code_bytes);
        }
    }
}
//cpu가 context switching 중일 때
void context_switching(CPU *cpu,int clock,int cpu_id){
    if(cpu[cpu_id].context_switch>0){
        cpu[cpu_id].context_switch--;
        //context switching 중에 idle이 돌고 있으므로 idle_time++
        cpu[cpu_id].idle_time++;
        
        //context switch 10 경과 후
        if(cpu[cpu_id].context_switch==0&&cpu[cpu_id].prev!=NULL&&cpu[cpu_id].prev!=cpu[cpu_id].current){

            printf("%04d CPU%d: Switched\tfrom: %03d\tto: %03d\n",
                clock, cpu_id + 1,
                cpu[cpu_id].prev->pid,
                cpu[cpu_id].current->pid);

            cpu[cpu_id].prev=cpu[cpu_id].current;
            
        }
        return;
    }
}

//cpu의 IO/CPU작업을 실행 및 프로세스 내의 작업 전환 및 프로세스가 terminated 됐을 때, context switch 10을 부여하고 후에 switching
void exec_cpu(CPU *cpu, int clock, int cpu_id,process *idle[]){
    if(cpu[cpu_id].context_switch>0) return;
    
    process *cur=cpu[cpu_id].current;
    
    //프로세스가 종료됐을 때, IO작업을 진행하고 있지 않을 때
    if(cur->terminated&&list_empty(&cpu[cpu_id].wait_q)){
        //레디 큐에 프로세스가 남음 -> 레디 큐에서 다음 프로세스 뽑고(레디큐에서 삭제) context switch
        if(!list_empty(&cpu[cpu_id].ready_q)){
            process *p;
            process *next;
            list_for_each_entry(p,&cpu[cpu_id].ready_q,ready){
                next=p;
                break;
            }
            list_del(&next->ready);
            cpu[cpu_id].prev=cur;
            cpu[cpu_id].current=next;
            cpu[cpu_id].context_switch=10;
        }
        //레디큐에 프로세스가 없음 -> idle context switch
        else{
            cpu[cpu_id].prev=cur;
            cpu[cpu_id].current=idle[cpu_id];
            cpu[cpu_id].context_switch=10;
        }
        return;
    }

    //프로세스가 idle일 때 + 레디 큐에 프로세스가 있을 때
    if(cur->pid==100&&!list_empty(&cpu[cpu_id].ready_q)&&list_empty(&cpu[cpu_id].wait_q)){
        process *p;
        process *next;
        list_for_each_entry(p,&cpu[cpu_id].ready_q,ready){
            next=p;
            break;
        }
        list_del(&next->ready);
        cpu[cpu_id].prev=cur;
        cpu[cpu_id].current=next;
        //첫 클락에 대해서 idle에서 해당 프로세스로의 context switching이 아닌 해당 프로세스를 그냥 바로 실행하는 것으로 간주
        if(clock!=0){
            cpu[cpu_id].context_switch=10;
            return;
        }
    }

    //첫 클락에 대해서 프로세스를 바꾸고, 바로 operation을 진행하기 위해 cur 갱신
    cur=cpu[cpu_id].current;

    //cur이 idle이 아닌 프로세스일 때
    if(cur->pid!=100){
        //프로세스 작업의 opcode
        code *op=&cur->operations[cur->pc];

        //cpu 작업일 떄
        if(op->opcode==0x00){
            op->length--;
            //작업을 완료하면 program count++ -> pc가 코드 개수만큼이 됐다면 프로세스 종료
            if(op->length==0){
                cur->pc++;
                if(cur->pc>=cur->code_bytes/2){
                    cur->terminated=1;
                }
            }
            
        }
        //IO 작업일 때
        else if(op->opcode==0x01){
            //IO 작업이 들어오자마자 start 출력
            printf("%04d CPU%d: OP_IO START len: %03d ends at: %04d\n", clock, cpu_id + 1, op->length, clock + op->length);
            
            //idle로 전환되면서 idle_time++
            cpu[cpu_id].idle_time++;
            //종료 시점
            cur->io_end_time=clock+op->length;
            //wait Queue에 추가해서 wait_check()로 관리 -> 1 clock 만큼 늦게 적용 됌
            list_add_tail(&cur->wait,&cpu[cpu_id].wait_q);

            //미리 program count++
            cur->pc++;
            

            cpu[cpu_id].prev=cur;
            cpu[cpu_id].current=idle[cpu_id];
        }
    }
    //그냥 idle이라면 idle_time++
    if(cur->pid==100){
        cpu[cpu_id].idle_time++;
    }
}
//idle 메모리 할당 해제
void free_idle(process *idle[]){
    for(int i=0;i<2;i++){
        free(idle[i]->operations);
        free(idle[i]);
    }
}
//모든 프로세스가 terminated flag가 붙었는지 확인인
int is_done(struct list_head *job_q){
    process *p;
    list_for_each_entry(p,job_q,job){
        if(!p->terminated) return 0;
    }
    return 1;
}

//exec_cpu()에서 wait Queue로 넣은 IO작업 프로세스를 루프를 돌며 임계 clock에 도달하면 wait Queue에서 삭제하고 다시 Ready에서 작업
//n clock에서 io 스위칭이 발생하면 n+s clock에 완료됨.
void wait_check(CPU *cpu,int clock,int cpu_id){
    process *cur,*next;
    list_for_each_entry_safe(cur,next,&cpu[cpu_id].wait_q,wait){
        if(cur->io_end_time<=clock){
            list_del(&cur->wait);

            if(cur->pc>=cur->code_bytes/2){
                cur->terminated=1;
            }
            cpu[cpu_id].current=cur;
        }
    }
}
int main(char argc,char* argv[]){
    LIST_HEAD(job_q);
    CPU cpu[2];
    int clock=0;

    process_load(&job_q);

    process *idle[2];

    //CPU, IDLE 초기화
    for(int i=0;i<2;i++){
        INIT_LIST_HEAD(&cpu[i].ready_q);
        INIT_LIST_HEAD(&cpu[i].wait_q);
        idle[i]=make_idle();
        cpu[i].current=idle[i];
        cpu[i].prev=idle[i];
        cpu[i].context_switch=0;
        cpu[i].idle_time=0;
    }

    while(1){   //출력 순서 context switching -> process loading -> IO operation
        context_switching(cpu,clock,0);
        context_switching(cpu,clock,1);

        ready_load(&job_q,cpu,clock,idle);

        wait_check(cpu,clock,0);
        wait_check(cpu,clock,1);
        if(is_done(&job_q)){        //IO 작업을 끝으로 프로그램을 종료하면 cpu idle Time을 계산하지 않음. 
            break;                  //IO 작업이 종료되는 타이밍이 한 박자 느림
        }
        exec_cpu(cpu,clock,0,idle);
        exec_cpu(cpu,clock,1,idle);
        
        clock++;
        if(is_done(&job_q)){
            if(cpu[0].context_switch>0) cpu[0].idle_time++;
            if(cpu[1].context_switch>0) cpu[1].idle_time++;
            break;
        }//CPU 작업을 끝으로 프로그램을 종료하면 마지막 clock까지 cpu작업을 해야 종료되므로 마지막에 clock을 한번 더 함 
         //context switching 중일 때, idle_time++
         
    }
    //성능 정리
    printf("*** TOTAL CLOCKS: %04d CPU1 IDLE: %04d CPU2 IDLE: %04d CPU1 UTIL: %2.2f%% CPU2 UTIL: %2.2f%% TOTAL UTIL: %2.2f%%\n",
        clock,cpu[0].idle_time,cpu[1].idle_time,100.0*(float)(clock-cpu[0].idle_time)/clock,100.0*(float)(clock-cpu[1].idle_time)/clock,
        100.0*(float)(2*clock-cpu[0].idle_time-cpu[1].idle_time)/(2*clock));
    //메모리 할당 해제
    free_process(&job_q);
    free_idle(idle);
    return 0;
}