/*
============================================================================================
File Name : 8e.c
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
// sigalrm_setitimer.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM (Setitimer)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, sigalrm_handler);

    // Configure the timer to trigger SIGALRM in 5 seconds
    timer.it_value.tv_sec = 5; // Initial delay
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No periodic interval
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGALRM (Setitimer). It will trigger in 5 seconds...\n");
    pause(); // Wait for signals

    return 0;
}
