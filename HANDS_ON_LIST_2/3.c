/*
============================================================================================
File Name : 3.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

3. Write a program to set (any one) system resource limit. Use setrlimit system call.

Data : 11/09/2024
============================================================================================
*/


/*
The setrlimit system call in Linux is used to set a limit on a specified system resource for the calling process. 
Each resource has two limits: a soft limit and a hard limit. The soft limit can be increased up to the hard limit, 
but the hard limit can only be increased by the superuser.

Below is an example program that sets the maximum file size that a process can create using the RLIMIT_FSIZE resource limit. T
his program sets a new soft limit on the file size to 1 MB and then retrieves and prints the new limits.

Explanation:

    struct rlimit: This structure holds the resource limits:
        rlim_cur: The soft limit, which can be modified up to the hard limit.
        rlim_max: The hard limit, which can be modified only by the superuser.

    Setting the Limits:
        The soft and hard limits are both set to 1 MB (1,048,576 bytes) using the setrlimit system call.

    Error Handling:
        If setrlimit or getrlimit fails, an error message is printed using perror, and the program exits with a failure status.

    Retrieving and Printing the Limits:
        The new limits are retrieved using getrlimit and then printed to the console.

        Notes:

    Resource Types: Other resource limits can be set by passing different values like RLIMIT_CPU, RLIMIT_NOFILE, etc., to setrlimit.
    Permissions: Some resources might require superuser permissions to change. For example, lowering the RLIMIT_NOFILE hard limit might require superuser access.
    Soft vs. Hard Limits: The soft limit is the value that actually affects the process, while the hard limit serves as a ceiling for the soft limit.
*/ 
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    // Set the maximum file size to 1 MB
    limit.rlim_cur = 1024 * 1024;  // Soft limit: 1 MB
    limit.rlim_max = 1024 * 1024;  // Hard limit: 1 MB
    setrlimit(RLIMIT_FSIZE, &limit);
    // Get and print the new limits
    getrlimit(RLIMIT_FSIZE, &limit);
    printf("New file size limit (soft): %ld bytes\n", limit.rlim_cur);
    printf("New file size limit (hard): %ld bytes\n", limit.rlim_max);

    return 0;
}

