/*
============================================================================================
File Name : 2.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

2. Write a program to print the system resource limits. Use getrlimit system call.

Data : 11/09/2024
============================================================================================
*/

/*
You can use the getrlimit system call to retrieve and print the current limits for various system resources. 

Explanation:

    print_limit Function:
        This function takes a resource identifier (like RLIMIT_CPU) and a name for that resource. 
        It uses getrlimit to retrieve the current limits and then prints them.
        If the limit is RLIM_INFINITY, it prints "Unlimited"; otherwise, it prints the numerical value of the limit.

    Resource Limits:
        The program prints limits for several resources, including CPU time (RLIMIT_CPU), maximum file size (RLIMIT_FSIZE), 
        data segment size (RLIMIT_DATA), stack size (RLIMIT_STACK), core file size (RLIMIT_CORE), resident set size (RLIMIT_RSS), 
        and the maximum number of open files (RLIMIT_NOFILE).

    Error Handling:
        If getrlimit fails for any resource, the program prints an error message and exits.

    Notes:

    RLIM_INFINITY: Represents an unlimited resource limit.
    Resource Limits: You can add or remove resources based on your needs. 
    The identifiers like RLIMIT_CPU, RLIMIT_FSIZE, etc., are defined in <sys/resource.h>.
    System-Dependent: The actual values and availability of these resource limits might vary 
    depending on the system and its configuration.
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) != 0) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("%-25s Soft Limit: ", name);
    if (limit.rlim_cur == RLIM_INFINITY)
        printf("Unlimited");
    else
        printf("%ld", limit.rlim_cur);

    printf(", Hard Limit: ");
    if (limit.rlim_max == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld\n", limit.rlim_max);
}

int main() {
    // Print CPU time limit
    print_limit(RLIMIT_CPU, "CPU time");

    // Print file size limit
    print_limit(RLIMIT_FSIZE, "File size");

    // Print data segment size limit
    print_limit(RLIMIT_DATA, "Data segment size");

    // Print stack size limit
    print_limit(RLIMIT_STACK, "Stack size");

    // Print core file size limit
    print_limit(RLIMIT_CORE, "Core file size");

    // Print resident set size limit
    print_limit(RLIMIT_RSS, "Resident set size");

    // Print number of open files limit
    print_limit(RLIMIT_NOFILE, "Number of open files");

    return 0;
}

