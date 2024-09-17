/*
============================================================================================
File Name : 28.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;
    // Generate a unique key for the message queue
    key = ftok("progfile", 65);
    // Create or access the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    // Get the current settings of the message queue
    msgctl(msgid, IPC_STAT, &buf);
    buf.msg_perm.mode = 0666;
    // Apply the modified settings to the message queue
    msgctl(msgid, IPC_SET, &buf);
    // Display the current permissions
    printf("Current permissions: %o\n", buf.msg_perm.mode);
    // Modify the permissions: set the permission to 0664 (rw-rw-r--)
    buf.msg_perm.mode = 0664;
    // Apply the modified settings to the message queue
    msgctl(msgid, IPC_SET, &buf);
    // Verify the change by getting the updated settings
    msgctl(msgid, IPC_STAT, &buf);
    // Display the updated permissions
    printf("Updated permissions: %o\n", buf.msg_perm.mode);

    return 0;
}
