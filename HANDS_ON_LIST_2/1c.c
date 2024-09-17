/*
============================================================================================
File Name : 1c.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF

Data : 11/09/2024
============================================================================================
*/

/*
The ITIMER_PROF timer decrements when the process is executing and when the system is executing on behalf of the process. 
When the timer expires, the kernel sends a SIGPROF signal to the process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_profalarm(int signum) {
    printf("ITIMER_PROF timer expired!\n");
}

int main() {
    struct itimerval timer;

    // Set the timer interval to 10 seconds and 10 microseconds
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    // Set the timer initial expiration to 10 seconds and 10 microseconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Set up signal handler for SIGPROF
    signal(SIGPROF, handle_profalarm);

    // Start the timer
    setitimer(ITIMER_PROF, &timer, NULL);

    // Loop to keep the program running
    while (1) {
        // Busy-wait loop to consume CPU and system time
    }

    return 0;
}
