/*
============================================================================================
File Name : 21a.c
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
        // Write a message to Program B
        int fd_write = open("fifo_a_to_b", O_WRONLY);
        write(fd_write, "Message from A\n", 15);
        close(fd_write);

        // Read the response from Program B
        int fd_read = open("fifo_b_to_a", O_RDONLY);
        read(fd_read, buffer, sizeof(buffer));
        printf("A received: %s", buffer);
        close(fd_read);

        sleep(1); // Add a small delay to allow the other program to respond
    }

    return 0;
}
