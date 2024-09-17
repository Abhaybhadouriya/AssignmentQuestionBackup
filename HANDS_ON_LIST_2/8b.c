/*
============================================================================================
File Name : 8b.c
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
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT (Interrupt signal)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, sigint_handler);
    printf("Waiting for SIGINT. Press Ctrl+C to send SIGINT...\n");

    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
