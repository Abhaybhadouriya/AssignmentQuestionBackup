/*
============================================================================================
File Name : 27a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 
27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};
int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    // Generate a unique key for the message queue
    key = ftok("progfile", 65);
    // Connect to the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    // Receiving message with flag 0 (blocking)
    printf("Receiving message with flag 0 (blocking)...\n");
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
    printf("Received message: %s\n", message.msg_text);
    // Receiving message with IPC_NOWAIT (non-blocking)
    printf("Receiving message with IPC_NOWAIT (non-blocking)...\n");
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message available in the queue.\n");
        } else {
            perror("msgrcv");
        }
    } else {
        printf("Received message: %s\n", message.msg_text);
    }

    // Clean up: remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
