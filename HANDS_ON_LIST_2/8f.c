/*
============================================================================================
File Name : 8f.c
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

Data : 12/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigvtalrm_handler(int signum) {
    printf("Caught SIGVTALRM (Virtual Timer)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, sigvtalrm_handler);

    // Configure the timer to trigger SIGVTALRM in 5 seconds
    timer.it_value.tv_sec = 5; // Initial delay
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No periodic interval
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    printf("Waiting for SIGVTALRM (Setitimer). It will trigger in 5 seconds...\n");
    while(1);

    return 0;
}
