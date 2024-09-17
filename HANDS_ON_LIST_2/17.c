/*
============================================================================================
File Name : 17.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

Data : 14/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // Create a pipe
    pipe(pipefd);

    // Fork to create the first child process for 'ls -l'
    pid = fork();

    if (pid == 0) { // First child
        // Redirect stdout to the write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]); // Close unused read end
        close(pipefd[1]); // Close the write end after dup2

        execlp("ls", "ls", "-l", (char *)NULL); // Execute 'ls -l'
        perror("execlp"); // If execlp fails
        return 1;
    }

    // Fork to create the second child process for 'wc'
    pid = fork();

    if (pid == 0) { // Second child
        // Redirect stdin to the read end of the pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]); // Close the read end after dup2
        close(pipefd[1]); // Close unused write end

        execlp("wc", "wc", (char *)NULL); // Execute 'wc'
        perror("execlp"); // If execlp fails
        return 1;
    }

    // Parent process
    close(pipefd[0]); // Close both ends of the pipe in the parent
    close(pipefd[1]);
    wait(NULL); // Wait for both children to finish
    wait(NULL);

    return 0;
}
