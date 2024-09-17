/*
============================================================================================
File Name : 18.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

Data : 14/09/2024
============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int pipefd1[2]; // Pipe for ls -l to grep ^d
    int pipefd2[2]; // Pipe for grep ^d to wc -l
    pid_t pid;

    // Create pipes
    pipe(pipefd1);
    pipe(pipefd2);
    
    // Fork for 'ls -l'
    pid = fork();

    if (pid == 0) { // Child process for 'ls -l'
        dup2(pipefd1[1], STDOUT_FILENO); // Redirect stdout to pipefd1
        close(pipefd1[0]); // Close unused read end
        close(pipefd2[0]); // Close both ends of second pipe
        close(pipefd2[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp");
        return 1;
    }

    // Fork for 'grep ^d'
    pid = fork();

    if (pid == 0) { // Child process for 'grep ^d'
        dup2(pipefd1[0], STDIN_FILENO); // Redirect stdin to pipefd1
        dup2(pipefd2[1], STDOUT_FILENO); // Redirect stdout to pipefd2
        close(pipefd1[1]); // Close unused write end
        close(pipefd2[0]); // Close unused read end
        execlp("grep", "grep", "^d", (char *)NULL);
        perror("execlp");
        return 1;
    }

    // Fork for 'wc -l'
    pid = fork();

    if (pid == 0) { // Child process for 'wc -l'
        dup2(pipefd2[0], STDIN_FILENO); // Redirect stdin to pipefd2
        close(pipefd1[0]); // Close both ends of first pipe
        close(pipefd1[1]);
        close(pipefd2[1]); // Close unused write end of second pipe
        execlp("wc", "wc", "-l", (char *)NULL);
        perror("execlp");
        return 1;
    }

    // Parent process
    close(pipefd1[0]); // Close both ends of both pipes
    close(pipefd1[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);

    // Wait for all child processes to complete
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
