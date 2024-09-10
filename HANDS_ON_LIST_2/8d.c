/*
============================================================================================
File Name : 8d.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)

Data : --/--/----
============================================================================================
*/
// sigalrm_alarm.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM (Alarm)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGALRM, sigalrm_handler);
    alarm(5); // Set an alarm for 5 seconds
    printf("Waiting for SIGALRM. It will trigger in 5 seconds...\n");

    pause(); // Wait for signals

    return 0;
}
