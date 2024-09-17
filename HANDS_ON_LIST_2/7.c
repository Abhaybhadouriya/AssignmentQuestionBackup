/*
============================================================================================
File Name : 7.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 7. Write a simple program to print the created thread ids.
Data : 12/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function to print its own thread ID
void *print_thread_id(void *arg) {
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3]; // Array for 3 thread IDs

    // Create threads
    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, print_thread_id, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
