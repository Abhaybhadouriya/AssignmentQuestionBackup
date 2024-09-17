/*
============================================================================================
File Name : 31b.c
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
    int init_val = 3;  // Initial value for counting semaphore
    // Step 1: Generate a unique key
    key = ftok("counting_sem", 65);
    // Step 2: Create a semaphore set with 1 semaphore (counting semaphore)
    semid = semget(key, 1, 0666 | IPC_CREAT);
    // Step 3: Initialize the counting semaphore value (for example, to 3)
    semctl(semid, 0, SETVAL, init_val);
    printf("Counting semaphore created and initialized to %d.\n", init_val);

    return 0;
}
