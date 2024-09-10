/*
============================================================================================
File Name : 20b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int fd = open("my_fifo", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Received: %s", buffer);
    close(fd);
    return 0;
}
