/*
============================================================================================
File Name : 15.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

15. Write a simple program to send some data from parent to the child process.

Data : 14/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];
    const char *message = "Hello from parent!";
    pipe(pipefd);
    pid = fork();
    if (pid == 0) { // Child process
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        close(pipefd[0]);
        printf("Child received: %s\n", buffer);
    } else { // Parent process
        close(pipefd[0]); // Close unused read end
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    }

    return 0;
}
