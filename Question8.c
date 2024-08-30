// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 10240

int main() {
    // give a name for a file to point
    // and open it with O_RDONLY access
    // ######################
    // a note for TAs please change the file name in your pc if your are checking
    int fd = open("Q7Sfile.txt", O_RDONLY); 
    // if fd is less than 0 that means there is an error
    if (fd < 0) {
        perror("There is an Error  while opening  the file");
        return 1;
    }
    // declaring the array of char to store tthe char byte by byte
    char buffer[MAX_BUFFER_SIZE];
    // declaring ssize_t varibale to track record the no of with to read or readed from file 
    ssize_t bytesRead, i = 0;
    // declaring the line valriable and initilizing to 1
    int line =1;
    // now reading the while using read fucntion 
    // here we  passed the FD and buffer and buffer size
    while((bytesRead = read(fd, buffer, MAX_BUFFER_SIZE))>0){
    // itareting through byte by byte or char by char to check a new line char "\n"
        for (ssize_t j = 0; j < bytesRead; ++j) {
            // if we encounter the new line char just enter in it
            if (buffer[j]== '\n') {
                // calculate the lenght from which index to which we have to read
                int len = j-i+1;
                // now print the line with line no 
                // and print the string using char[] by defining the line size
                // for 1st it will run from 0 to the first new line character' \n'
                // then it increament the i index from 0 to j+1 for next line and so on
                printf("%d : %.*s\n",line++,len,buffer+i);
                char ch;
                ch = getchar();
                // incrementing the i index to start of new linel
                i = j+1;
            }
            // because after some time i become greater than j
            // i=0;
        }
        }
    // of this varible is less then it means there is an error while reading
        if (bytesRead < 0) {
        perror("Please check again there is an Error while reading this file");
        // closing the FD and exiting with code 0
        close(fd);
        // return error code
        return 1;
    }
    // close fd
    close(fd);
    // return success code 
    return 0;
}
