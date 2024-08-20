#include <stdio.h>
#include <sched.h>
#include <unistd.h>
int main() {
    int pid;
    int policy;
    // getting the process ID of current process to retrive the SCHEDULING policy
    pid = getpid();  // Get current process ID
    // using below function by passing PID of current function we can get scheduling policy
    policy = sched_getscheduler(pid);
    // why iam doing this because OS uses multiple type of policies like below  
    // SCHED_FIFO
    // SCHED_RR
    // SCHED_OTHER
    // SCHED_BATCH
    // SCHED_IDLE
    // so to get correct priory we need current scheduling algo
    printf("Max realtime priority of program is : %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("Min realtime priority of program is : %d\n", sched_get_priority_min(SCHED_FIFO));
   
    return 0;
}
