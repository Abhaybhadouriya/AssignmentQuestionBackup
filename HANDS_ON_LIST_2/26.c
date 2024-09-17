/*
============================================================================================
File Name : 26.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 26. Write a program to send messages to the message queue. Check $ipcs -q
Data : 16/09/2024
============================================================================================
*/
/*

Here is a C program that sends messages to a System V message queue. It uses the msgsnd() system call to send messages to the queue,
 and you can use the ipcs -q command to inspect the state of message queues.
 
 Explanation:

    ftok("progfile", 65): Generates a unique key for the message queue. The progfile must be present in the current directory, or you need to create it using touch progfile.

    msgget(): This function either creates or accesses an existing message queue. The 0666 permission allows both read and write access for everyone.

    struct msg_buffer: This structure holds the message type (msg_type) and the actual message content (msg_text).

    msgsnd(): Sends the message to the queue. It takes the message queue ID, a pointer to the message, the size of the message content, and flags (we set it to 0 for default behavior).

    fgets(): Reads the message from the user and stores it in the msg_text field.

    system("ipcs -q"): After sending the message, this command runs ipcs -q to display the current state of all message queues.



Notes:

    Use the msgctl() function to remove the message queue later, or you can manually delete it using the ipcrm command.
    You can write a corresponding receiver program using msgrcv() to read messages from the queue.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65);  // progfile should exist in the directory

    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;
    message.msg_type = 1;  // Message type can be any positive number
    // Get the message from the user to send
    printf("Enter the message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);
    // Send the message to the message queue
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    printf("Message sent: %s\n", message.msg_text);
    // Print the message queue status
    system("ipcs -q");
    return 0;
}
