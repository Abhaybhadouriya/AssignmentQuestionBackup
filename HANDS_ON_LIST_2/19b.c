/*
============================================================================================
File Name : 19b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

19.Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function

Data : --/--/----
============================================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main() {
    // c. Create FIFO using mknod system call
    if (mknod("my_fifo_mknod", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    } else {
        printf("FIFO created using mknod.\n");
    }

    // d. Create FIFO using mkfifo library function
    if (mkfifo("my_fifo_mkfifo", 0666) == -1) {
        perror("mkfifo");
        return 1;
    } else {
        printf("FIFO created using mkfifo.\n");
    }

    return 0;
}
