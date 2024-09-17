/*
============================================================================================
File Name : 29.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 29. Write a program to remove the message queue.
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() {
    key_t key;
    int msgid;
    // Generate a unique key for the message queue
    key = ftok("progfile", 65);
    // Connect to the message queue (assumes it already exists)
    msgid = msgget(key, 0666 | IPC_CREAT);
    // Remove the message queue using msgctl and IPC_RMID
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message queue removed successfully.\n");
    return 0;
}
