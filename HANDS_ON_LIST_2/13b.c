/*
============================================================================================
File Name : 13b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t target_pid = /* Replace with the PID of the first program */;
    kill(target_pid, SIGSTOP); // Send SIGSTOP signal
    printf("SIGSTOP sent to process %d\n", target_pid);
    return 0;
}
