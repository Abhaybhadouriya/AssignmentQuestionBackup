/*
============================================================================================
File Name : 25.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Data : 16/09/2024
============================================================================================
*/

/*
Explanation of Each Field:

    buf.msg_perm.mode: This gives the access permissions for the message queue (like 0666 for read and write access).

    buf.msg_perm.uid and buf.msg_perm.gid: These fields hold the UID and GID of the owner of the message queue.

    buf.msg_stime and buf.msg_rtime: These fields hold the time of the last message sent and received, respectively.

    buf.msg_ctime: This holds the time when the last change was made to the message queue (e.g., when permissions were changed).

    buf.__msg_cbytes: This gives the current size of the message queue in bytes (i.e., the total size of all messages currently in the queue).

    buf.msg_qnum: This gives the current number of messages in the queue.

    buf.msg_qbytes: This gives the maximum number of bytes allowed in the message queue.

    buf.msg_lspid and buf.msg_lrpid: These are the PIDs of the last process to send and receive messages, respectively.

    Notes:

    The program uses ftok to generate a unique key based on a file (progfile) and a project identifier (65). 
    Make sure to create this file (touch progfile) before running the program.
    
    The program assumes that the message queue already exists. 
    You can use another program or ipcs to confirm the existence of a message queue or create a new one.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <time.h>

void print_time(time_t t) {
    if (t == 0) {
        printf("Not set\n");
    } else {
        printf("%s", ctime(&t));
    }
}

int main() {
    // Create a unique key for the message queue
    key_t key = ftok("progfile", 65);

    // Get the message queue ID (assumes message queue already exists)
    int msqid = msgget(key, 0666 | IPC_CREAT);
   
    // Declare msqid_ds structure to hold message queue information
    struct msqid_ds buf;

    // Get the message queue details
    msgctl(msqid, IPC_STAT, &buf);
    // a. Access permission (mode)
    printf("a. Access permission: %o\n", buf.msg_perm.mode);
    // b. UID and GID of owner
    printf("b. UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
    // c. Time of last message sent and received
    printf("c. Time of last message sent: ");
    print_time(buf.msg_stime);
    printf("   Time of last message received: ");
    print_time(buf.msg_rtime);
    // d. Time of last change in the message queue
    printf("d. Time of last change in the queue: ");
    print_time(buf.msg_ctime);
    // e. Size of the queue in bytes
    printf("e. Current size of the queue (in bytes): %lu\n", buf.__msg_cbytes);
    // f. Number of messages in the queue
    printf("f. Number of messages in the queue: %lu\n", buf.msg_qnum);
    // g. Maximum number of bytes allowed in the queue
    printf("g. Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);
    // h. PID of the last msgsnd and msgrcv
    printf("h. PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("   PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}
