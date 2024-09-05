// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>

void printCurrentPolicy(int policy) {
    switch (policy) {
        case SCHED_OTHER:
            printf("Current : SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current : SCHED_FIFO \n");
            break;
        case SCHED_RR:
            printf("Current : SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
    }
}

int main() {
    int pid = getpid();  
    struct sched_param param;
    printCurrentPolicy(sched_getscheduler(pid));
    param.sched_priority = 10;
    sched_setscheduler(pid, SCHED_FIFO, &param);
    printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);
    printCurrentPolicy(sched_getscheduler(pid));
    param.sched_priority = 15; 
    sched_setscheduler(pid, SCHED_RR, &param);
    printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);
    printCurrentPolicy(sched_getscheduler(pid));

    return 0;
}
