/*
============================================================================================
File Name : 20a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Data : 15/09/2024
============================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("my_fifo", 0666);
    int fd = open("my_fifo", O_WRONLY);
    write(fd, "Hello, Reader!\n", 15);
    close(fd);
    return 0;
}
