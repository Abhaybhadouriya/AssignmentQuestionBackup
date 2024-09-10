/*
============================================================================================
File Name : 21b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buffer[100];

    // Create two FIFOs
    mkfifo("fifo_a_to_b", 0666);
    mkfifo("fifo_b_to_a", 0666);

    while (1) {
        // Read the message from Program A
        int fd_read = open("fifo_a_to_b", O_RDONLY);
        read(fd_read, buffer, sizeof(buffer));
        printf("B received: %s", buffer);
        close(fd_read);

        // Write a response to Program A
        int fd_write = open("fifo_b_to_a", O_WRONLY);
        write(fd_write, "Message from B\n", 15);
        close(fd_write);

        sleep(1); // Add a small delay to allow the other program to respond
    }

    return 0;
}
