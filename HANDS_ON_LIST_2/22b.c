/*
============================================================================================
File Name : 22b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    char buffer[100];
    fd_set read_fds;
    struct timeval timeout;
    int fd, retval;

    mkfifo("my_fifo", 0666);
    fd = open("my_fifo", O_RDONLY | O_NONBLOCK);

    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    retval = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select");
    } else if (retval) {
        read(fd, buffer, sizeof(buffer));
        printf("Received: %s", buffer);
    } else {
        printf("No data within 10 seconds.\n");
    }

    close(fd);
    return 0;
}
