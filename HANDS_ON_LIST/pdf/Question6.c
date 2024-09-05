// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

#include <unistd.h>
#include <stdio.h>

int main() {
    char maxBufferSpace[500];
    // Diff between stdin vs STDIN_FILENO
    // 1. stdin - is just a file pointer to ' FIle * ' defined in <stdio.h>
    //    it uses higher level I/O function like fscanf and fgets and fread
    // 2. STDIN_FILENO is an integer constant representing the FD for standard input in <unistd.h>
    //    typically has the value `0`
    //    it uses low level system calls like read and write
    //    STDIN_FILE - interact with OS directly bypassing standard library buffering
    //    so we have direct control over I/O

    // abstraction 
    // std -> highlevel abstraction offers buffered I/O - slow
    // stdin_fileno -> unbuffered I/O , direct access to system I/O,LL abstraction - faster
    // Buffered I/O -> instead of transferring data immediately to or from file or device
    // data is first stored in a buffer, once it is full then data is transferred all at once
    // by doing this system calls are redunce but performance of program is decreased
    // and for reading 'fgets' and 'fread' instead of making system call to fetach data immediatley
    // it reads the block of data and requested data return to the program and process so on


    // there are 3 FD 
    //     1. STDIN_FILENO (0){stdin} - take input from keyboard or pipe etc
    //     2. STDOUT_FILENO (1){stdout} -  write o/p
    //     3. STDERR_FILENO (2){stderr} - for error messages writing 

    // read is LL function used read from FD such as file,pipe. it is unbuffered
    // on success return the no of bytes it reads. 
    printf("Write Something \n");
    ssize_t bytesReadSize = read(STDIN_FILENO, maxBufferSpace, sizeof(maxBufferSpace));

    // Writing with 
    // write(fd,buff[],size);
    // this method is used to write in a file using FD 
    // 3rd arg is provided to specify the length of data we are going to write
    // on succress return the no of bytes it actually returned
    // it is block I/O - it block the program untill it the data is written to the file or device
    // handle partial writes  - if it block by system then check if no bytes  are fewer then requested then just retry
    write(STDOUT_FILENO, maxBufferSpace, bytesReadSize);
    

    return 0;
}
