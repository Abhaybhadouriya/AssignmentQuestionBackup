/*
============================================================================================
File Name : 6.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 6. Write a simple program to create three threads.
Data : --/--/----
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function that will be executed by each thread
void *thread_function(void *arg) {
    int thread_num = *(int *)arg;
    printf("Hello from thread %d\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[3]; // Array to hold thread IDs
    int thread_args[3];   // Array to hold arguments for each thread

    // Create 3 threads
    for (int i = 0; i < 3; ++i) {
        thread_args[i] = i + 1; // Pass thread number as argument
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
