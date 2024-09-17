/*
============================================================================================
File Name : 24.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 24. Write a program to create a message queue and print the key and message queue id.
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("msgfile", 65); // Generate key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue
    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    // Cleanup: Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
