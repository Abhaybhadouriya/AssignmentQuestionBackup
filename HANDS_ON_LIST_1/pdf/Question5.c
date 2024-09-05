// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 5. Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// defining basefile name 
#define NAME_OF_THE_BASE_FILE "testfile_Q5_"
#define EXTENSION ".txt"
// as explained in question setted the file count to 5 
#define FILE_COUNT 5

int main() {
    // declaring the array of int for file descriptor of size 5
    int file_descriptors_array[FILE_COUNT];
    // declaring the array of char for filename 
    char filename[256];

    int i;

    while (1) {
        for (i = 0; i < FILE_COUNT; ++i) {
            // snprintf() used to format and store a string in a buffer with specified size 
            // 1st param filename is bufffer where formatted data is stored 
            // 2nd param the size of the buffer
            // 3rd param %s%d%s are replaces by the filename + number + extension
            // 4th param base name of the file
            // 5th param number of the file
            // 6th param extension
            snprintf(filename, sizeof(filename), "%s%d%s", NAME_OF_THE_BASE_FILE, i,EXTENSION);
            // create a file with specified name and 0666 permission and open it with Read write permission
            file_descriptors_array[i] = open(filename, O_CREAT | O_RDWR | O_APPEND, 0666);

            if (file_descriptors_array[i] < 0) {
                perror("There is an Error  while opening file");
                exit(EXIT_FAILURE);
            }

            char *tempdata = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
            if (write(file_descriptors_array[i], tempdata, strlen(tempdata)) < 0) {
                perror("Error writing to file");
                close(file_descriptors_array[i]);
                exit(EXIT_FAILURE);
            }
        }

        // Sleeping for 5 sec so program do not use extra time
        sleep(5);

        // Closing all the opened files
        for (i = 0; i < FILE_COUNT; ++i) {
            close(file_descriptors_array[i]);
        }
    }

    return 0;
}
