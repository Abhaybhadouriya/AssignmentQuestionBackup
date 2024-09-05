// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 7. Write a program to copy file1 into file2 ($cp file1 file2).
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF_SIZE 10024

int main() {
    char sourcefileName[250];
    printf("Enter Source File name \n");
    if(fgets(sourcefileName,sizeof(sourcefileName),stdin) == NULL) {
        perror("Error reading input");
        return 1;
    }
    sourcefileName[strcspn(sourcefileName,"\n")] = '\0';
    char destfileName[250];
    printf("Enter Destination File name \n");
    fgets(destfileName,sizeof(destfileName),stdin);
    destfileName[strcspn(destfileName,"\n")]='\0';    
    int sourceFileDesp = open(sourcefileName, O_RDONLY);
    if (sourceFileDesp< 0) {
        perror("There is an error while openning a Source File:");
        return 1;
    }

    int destFileDesp = open(destfileName, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (destFileDesp < 0) {
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
