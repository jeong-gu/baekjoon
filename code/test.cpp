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
    int remain_time;
    bool terminated;

    struct list_head job,ready,wait;
} process;

//CPU 구조
typedef struct{
    struct list_head ready_q;
    struct list_head wait_q;

    process *current;
    int context_switch;
    int idle_time;
    bool is_idle;
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
void print_process_reverse(struct list_head *job_q){
    process *cur;
    
    //모든 노드 역순으로 순회
    list_for_each_entry_reverse(cur,job_q,job){
        printf("PID: %03d\tARRIVAL: %03d\tCODESIZE: %03d\n",cur->pid,cur->arrival_time,cur->code_bytes);
        //code 개수
        int it=cur->code_bytes/2; 
        for(int i=0;i<it;i++){
            printf("%d %d\n",cur->operations[i].opcode,cur->operations[i].length);
        }
    }
}
#define CONTEXT_SWITCH_TIME 10

// process, code, CPU 구조체는 이미 선언되어 있다고 가정

// IDLE 프로세스 생성
process* make_idle_process() {
    process *idle = malloc(sizeof(*idle));
    idle->pid = 100;
    idle->arrival_time = 0;
    idle->code_bytes = 2;
    idle->operations = malloc(sizeof(code));
    idle->operations[0].opcode = 0xFF;
    idle->operations[0].length = 9999;

    idle->pc = 0;
    idle->remain_time = 9999;
    idle->terminated = 0;

    INIT_LIST_HEAD(&idle->job);
    INIT_LIST_HEAD(&idle->ready);
    INIT_LIST_HEAD(&idle->wait);

    return idle;
}

// job queue에서 도착 프로세스를 ready queue로 옮김
void check_arrival(struct list_head *job_q, CPU *cpu, int clock) {
    process *p, *n;
    list_for_each_entry_safe(p, n, job_q, job) {
        if (p->arrival_time == clock) {
            list_del(&p->job);
            int len0 = 0, len1 = 0;
            struct list_head *pos;

            list_for_each(pos, &cpu[0].ready_q) len0++;
            list_for_each(pos, &cpu[1].ready_q) len1++;

            if (len0 <= len1)
                list_add_tail(&p->ready, &cpu[0].ready_q);
            else
                list_add_tail(&p->ready, &cpu[1].ready_q);

            printf("%d: LOAD PID %03d\n", clock, p->pid);
        }
    }
}

// 모든 작업 완료되었는지 확인
int all_done(CPU *cpu, struct list_head *job_q) {
    process *p;
    list_for_each_entry(p, job_q, job) {
        if (!p->terminated) return 0;
    }
    for (int i = 0; i < 2; i++) {
        if (cpu[i].current->pid != 100 || cpu[i].context_switch > 0) return 0;
    }
    return 1;
}
int main() {
   LIST_HEAD(job_q);
   CPU cpu[2];
   int clock = 0;

   // 2-1의 process_load 함수로 job_q 초기화
   process_load(&job_q);

   // CPU 초기화
   for (int i = 0; i < 2; i++) {
       INIT_LIST_HEAD(&cpu[i].ready_q);
       INIT_LIST_HEAD(&cpu[i].wait_q);
       cpu[i].current = make_idle_process();
       cpu[i].context_switch = 0;
       cpu[i].idle_time = 0;
       cpu[i].is_idle = 1;
   }

   // 시뮬레이터 루프
   while (!all_done(cpu, &job_q)) {
       check_arrival(&job_q, cpu, clock);

       for (int i = 0; i < 2; i++) {
           CPU *c = &cpu[i];
           process *p = c->current;

           // context switching 중이라면 대기
           if (c->context_switch > 0) {
               c->context_switch--;
               continue;
           }

           // 현재 프로세스 작업 처리
           if (p->pid == 100) {
               c->idle_time++;
               continue;
           }

           // 현재 작업이 끝났다면 다음으로
           if (p->remain_time == 0) {
               p->pc++;
               if (p->pc >= p->code_bytes / 2) {
                   p->terminated = 1;
                   c->current = make_idle_process();
                   c->context_switch = CONTEXT_SWITCH_TIME;
                   printf("%d: TERMINATE PID %03d\n", clock, p->pid);
                   continue;
               }

               // 새 작업 준비
               code curr = p->operations[p->pc];
               p->remain_time = curr.length;

               if (curr.opcode == 1) { // IO 작업이면 기다리기
                   printf("%d: PID %03d IO start (%d)\n", clock, p->pid, curr.length);
                   c->idle_time += curr.length;
                   clock += curr.length;
                   p->pc++;
                   continue;
               }
           }

           // 현재 작업 수행 중이면 시간 줄이기
           if (p->remain_time > 0) {
               p->remain_time--;
           }

           // 작업이 끝났다면 context switching 시작
           if (p->remain_time == 0) {
               list_for_each_entry(p, &c->ready_q, ready) {
                   list_del(&p->ready);
                   c->current = p;
                   c->context_switch = CONTEXT_SWITCH_TIME;
                   printf("%d: CONTEXT SWITCH to PID %03d\n", clock, p->pid);
                   break;
               }
           }
       }

       clock++;
   }

   // 결과 출력
   printf("\n== Final Report ==\n");
   for (int i = 0; i < 2; i++) {
       printf("CPU%d: idle time = %d\n", i, cpu[i].idle_time);
   }

   return 0;
}