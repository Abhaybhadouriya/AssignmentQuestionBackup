// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 7. Write a program to copy file1 into file2 ($cp file1 file2).
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 10024

int main() {
    char sourcefileName[255];
    printf("Enter Source File name \n");
    gets(sourcefileName);

    char destfileName[255];
    printf("Enter Destination File name \n");
    gets(destfileName);
    
    int sourceFileDesp = open(sourcefileName, O_RDONLY);
    int destFileDesp = open(destfileName, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (sourceFileDesp< 0 || destFileDesp < 0) {
        perror("There is an error while openning a File");
        return 1;
    }

    char data[MAX_BUF_SIZE];
    ssize_t bytesReaded = read(sourceFileDesp, data, MAX_BUF_SIZE);
    if (write(destFileDesp, data, bytesReaded) != bytesReaded) {
            perror("There is an error while Writing the data to Destination file");
            return 1;
        }

    close(sourceFileDesp);
    close(destFileDesp);
    return 0;
}
