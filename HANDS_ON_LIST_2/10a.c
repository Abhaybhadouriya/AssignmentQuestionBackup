/*
============================================================================================
File Name : 10a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Data : --/--/----
============================================================================================
*/
// sigsegv_handler.c
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

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction SIGSEGV");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGSEGV...\n");

    // Trigger a segmentation fault for testing
    int *ptr = NULL;
    *ptr = 0;

    return 0;
}
