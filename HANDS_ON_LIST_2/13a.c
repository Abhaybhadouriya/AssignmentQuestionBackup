/*
============================================================================================
File Name : 13a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Data : 14/09/2024
============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handler(int sig) {
    printf("Caught SIGSTOP (should not happen).\n");
}

int main() {
    signal(SIGSTOP, sigstop_handler);
    printf("Waiting for SIGSTOP...\n");
    while (1); // Wait indefinitely for signals
    return 0;
}
