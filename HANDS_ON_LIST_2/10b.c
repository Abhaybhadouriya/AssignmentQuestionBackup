/*
============================================================================================
File Name : 10b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Data : --/--/----
============================================================================================
*/
// sigint_handler.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT (Interrupt signal)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGINT. Press Ctrl+C to send SIGINT...\n");

    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
