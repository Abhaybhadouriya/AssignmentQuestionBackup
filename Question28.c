// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
//28. Write a program to get maximum and minimum real time priority.

#include <stdio.h>
#include <sched.h>
#include <unistd.h>
void printPri(char *string,int SCHED_POLICY){
printf("Max realtime priority of %s Scheduler is : %d\n",string, sched_get_priority_max(SCHED_POLICY));
printf("Min realtime priority of %s Scheduler is : %d\n",string, sched_get_priority_min(SCHED_POLICY));
}

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
    // so to get correct priory we need current scheduling algo
    printPri("SCHED_FIFO",SCHED_FIFO);
    printPri("SCHED_RR",SCHED_RR);
    printPri("SCHED_OTHER",SCHED_OTHER);
   
    return 0;
}


