/*
============================================================================================
File Name : 10c.c
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

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE (Floating-point exception)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigfpe_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGFPE, &sa, NULL);
    printf("Waiting for SIGFPE...\n");

    // Trigger a floating-point exception for testing
    // int zero = 0;
    int result = 1 / 0; // This will cause SIGFPE

    return 0;
}
