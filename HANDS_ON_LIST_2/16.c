/*
============================================================================================
File Name : 16.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.

Data : 14/09/2024
============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2]; // Pipe for parent to child
    int pipe2[2]; // Pipe for child to parent
    pid_t pid;
    char parent_message[] = "Hello from parent!";
    char child_message[] = "Hello from child!";
    char buffer[100];
    pipe(pipe1);
    pipe(pipe2);
    pid = fork();
    if (pid == 0) { // Child process
        close(pipe1[1]); // Close unused write end of pipe1
        close(pipe2[0]); // Close unused read end of pipe2
        // Read message from parent
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        // Send message to parent
        write(pipe2[1], child_message, strlen(child_message) + 1);
        close(pipe1[0]);
        close(pipe2[1]);
    } else { // Parent process
        close(pipe1[0]); // Close unused read end of pipe1
        close(pipe2[1]); // Close unused write end of pipe2

        // Send message to child
        write(pipe1[1], parent_message, strlen(parent_message) + 1);

        // Read message from child
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(pipe1[1]);
        close(pipe2[0]);
    }
    return 0;
}
