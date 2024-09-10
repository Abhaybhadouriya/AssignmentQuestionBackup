/*
============================================================================================
File Name : 10c.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Data : --/--/----
============================================================================================
*/
// sigfpe_handler.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE (Floating-point exception)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigfpe_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction SIGFPE");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGFPE...\n");

    // Trigger a floating-point exception for testing
    // int zero = 0;
    int result = 1 / 0; // This will cause SIGFPE

    return 0;
}
