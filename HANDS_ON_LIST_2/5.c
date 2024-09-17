/*
============================================================================================
File Name : 5.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 

5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory

Data : 11/09/2024
============================================================================================
*/
/*
Explanation:

    a. Maximum Length of Arguments to exec:
        sysconf(_SC_ARG_MAX) returns the maximum number of bytes that can be passed to the exec family of functions, 
        including environment variables.

    b. Maximum Number of Simultaneous Processes per User ID:
        sysconf(_SC_CHILD_MAX) returns the maximum number of simultaneous processes that a user can create.

    c. Number of Clock Ticks per Second:
        sysconf(_SC_CLK_TCK) returns the number of clock ticks (jiffies) per second. This is used in timing calculations.

    d. Maximum Number of Open Files:
        sysconf(_SC_OPEN_MAX) returns the maximum number of files that a process can have open simultaneously.

    e. Size of a Page:
        sysconf(_SC_PAGESIZE) or _SC_PAGE_SIZE returns the size of a memory page in bytes.

    f. Total Number of Pages in Physical Memory:
        sysconf(_SC_PHYS_PAGES) returns the total number of memory pages in the system.

    g. Number of Currently Available Pages in Physical Memory:
        sysconf(_SC_AVPHYS_PAGES) returns the number of currently available pages in physical memory.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("a. Maximum length of arguments to exec: %ld bytes\n", arg_max);

    // b. Maximum number of simultaneous processes per user ID
    long max_processes = sysconf(_SC_CHILD_MAX);
    printf("b. Maximum number of simultaneous processes per user ID: %ld\n", max_processes);

    // c. Number of clock ticks (jiffy) per second
    long clock_ticks = sysconf(_SC_CLK_TCK);
    printf("c. Number of clock ticks (jiffy) per second: %ld\n", clock_ticks);

    // d. Maximum number of open files
    long open_files = sysconf(_SC_OPEN_MAX);
    printf("d. Maximum number of open files: %ld\n", open_files);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    printf("e. Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("f. Total number of pages in the physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("g. Number of currently available pages in the physical memory: %ld\n", avail_pages);

    return 0;
}
