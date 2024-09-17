/*
============================================================================================
File Name : 8a.c
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

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);
    printf("Waiting for SIGSEGV...\n");

    // Trigger a segmentation fault for testing
    int *ptr = NULL;
    *ptr = 0;

    return 0;
}
