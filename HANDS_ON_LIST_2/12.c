/*
============================================================================================
File Name : 12.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.

Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) { // Parent process
        sleep(2); // Give the child time to send the signal
        printf("Parent process exiting.\n");
    } else if (pid == 0) { // Child process
        printf("Child sending SIGKILL to parent.\n");
        kill(getppid(), SIGKILL); // Kill the parent process
        sleep(5); // Keep the child alive to observe orphan state
        printf("Child process now orphaned, adopted by init.\n");
    }

    return 0;
}
