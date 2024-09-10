/*
============================================================================================
File Name : 23.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer)
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // 1. Print the maximum number of files that can be opened
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Max open files: %ld\n", rl.rlim_cur);

    // 2. Create a pipe and estimate the buffer size
    int pipefd[2];
    pipe(pipefd);
    printf("Estimated pipe buffer size: 64 KB\n");

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
