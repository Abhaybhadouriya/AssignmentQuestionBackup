/*
============================================================================================
File Name : 11.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("SIGINT received but ignored.\n");
}

int main() {
    struct sigaction sa;

    // Step 1: Ignore the SIGINT signal
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is now ignored. Press Ctrl+C.\n");
    sleep(5); // Give time to test ignoring SIGINT

    // Step 2: Reset SIGINT to its default action
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT default action restored. Press Ctrl+C again.\n");
    sleep(5); // Give time to test default SIGINT behavior

    return 0;
}
