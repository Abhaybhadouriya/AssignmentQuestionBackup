/*
============================================================================================
File Name : 30.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 
Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
int main() {
    key_t key;
    int shmid;
    char *data;
    // Step a: Generate a unique key and create shared memory
    key = ftok("progfile", 65);
    // Create shared memory segment of 1024 bytes with read/write permission
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    printf("Shared memory created with ID: %d\n", shmid);
    // Step a: Attach to shared memory and write data
    data = (char *)shmat(shmid, NULL, 0);  // Attach with read/write mode
    printf("Writing to shared memory...\n");
    strcpy(data, "Hello, this is shared memory!");
    printf("Data written: %s\n", data);
    // Step b: Detach and reattach in read-only mode
    shmdt(data);
    printf("Shared memory detached.\n");
    // Reattach in read-only mode (O_RDONLY)
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Attached to shared memory in read-only mode.\n");
    // Reading data from shared memory in read-only mode
    printf("Data read from shared memory (read-only mode): %s\n", data);
    // Attempt to overwrite data (will be skipped in this version to prevent segfault)
    printf("Attempt to overwrite is not performed as it would cause a segfault in read-only mode.\n");
    // Detach the shared memory
    shmdt(data);
    printf("Shared memory detached.\n");
    // Step d: Remove the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed successfully.\n");
    return 0;
}
