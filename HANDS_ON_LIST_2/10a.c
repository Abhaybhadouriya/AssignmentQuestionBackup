/*
============================================================================================
File Name : 10a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Data : 13/09/2024
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
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    printf("Waiting for SIGSEGV...\n");

    // Trigger a segmentation fault for testing
    int *ptr = NULL;
    *ptr = 0;

    return 0;
}
