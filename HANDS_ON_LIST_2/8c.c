/*
============================================================================================
File Name : 8c.c
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
// sigfpe_signal.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE (Floating-point exception)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    printf("Waiting for SIGFPE...\n");

    // Trigger a floating-point exception for testing
    int result = 1 / 0; // This will cause SIGFPE

    return 0;
}
