/*
============================================================================================
File Name : 14.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[100];
    const char *message = "Hello from pipe!";

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Write to the pipe
    write(pipefd[1], message, strlen(message) + 1);
    close(pipefd[1]); // Close the write end after writing

    // Read from the pipe
    read(pipefd[0], buffer, sizeof(buffer));
    close(pipefd[0]); // Close the read end after reading

    printf("Received message: %s\n", buffer);

    return 0;
}
