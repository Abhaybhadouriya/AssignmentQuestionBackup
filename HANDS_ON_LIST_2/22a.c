/*
============================================================================================
File Name : 22a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description :  Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO
Data : 15/09/2024
============================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd;
    mkfifo("my_fifo", 0666);
    fd = open("my_fifo", O_WRONLY);
    sleep(2); // Sleep for 2 seconds to simulate some delay
    write(fd, "Hello from writer!\n", 19);
    close(fd);
    return 0;
}
