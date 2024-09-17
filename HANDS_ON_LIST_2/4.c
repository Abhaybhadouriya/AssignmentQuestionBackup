/*
============================================================================================
File Name : 4.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

Data : 11/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// Function to read the Time Stamp Counter
static __inline__ uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    pid_t ppid;
    int i;

    // Measure start time
    start = rdtsc();

    // Execute getppid() 100 times
    for (i = 0; i < 100; i++) {
        ppid = getppid();
    }

    // Measure end time
    end = rdtsc();

    // Calculate and print the difference in TSC (cycles)
    printf("Time taken for 100 getppid() calls: %lu CPU cycles\n", end - start);

    return 0;
}
