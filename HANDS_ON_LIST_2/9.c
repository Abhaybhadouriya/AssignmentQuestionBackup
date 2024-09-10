/*
============================================================================================
File Name : 9.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description :  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler that does nothing (ignore SIGINT)
void ignore_signal(int signum) {
    // Do nothing; just ignore the signal
}

int main() {
    // Ignore SIGINT
    signal(SIGINT, ignore_signal);
    printf("SIGINT is now being ignored. Press Ctrl+C to test.\n");

    // Wait for 10 seconds to show that SIGINT is ignored
    sleep(10);

    // Reset SIGINT to default action
    signal(SIGINT, SIG_DFL);
    printf("SIGINT has been reset to default action. Press Ctrl+C to test.\n");

    // Wait indefinitely to show the default behavior
    while (1) {
        pause(); // Wait for a signal
    }

    return 0;
}
