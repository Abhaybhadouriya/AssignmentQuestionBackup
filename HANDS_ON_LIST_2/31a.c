/*
============================================================================================
File Name : 31a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
int main() {
    key_t key;
    int semid;
    struct sembuf sb = {0, -1, 0};  // Semaphore buffer structure
    // Step 1: Generate a unique key
    key = ftok("binary_sem", 65);
    // Step 2: Create a semaphore set with 1 semaphore (binary semaphore)
    semid = semget(key, 1, 0666 | IPC_CREAT);
    // Step 3: Initialize the semaphore value to 1 (binary semaphore)
    semctl(semid, 0, SETVAL, 1);
    printf("Binary semaphore created and initialized to 1.\n");
    return 0;
}
