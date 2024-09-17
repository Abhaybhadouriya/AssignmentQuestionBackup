/*
============================================================================================
File Name : 27b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 
27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Prepare the message
    message.msg_type = 1; // Message type must be a positive integer
    printf("Enter message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    // Remove the newline character added by fgets
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0';

    // Send the message
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
    } else {
        printf("Message sent: %s\n", message.msg_text);
    }

    return 0;
}
