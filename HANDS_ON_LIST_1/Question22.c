// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 22. Write a program, open a file, call fork, 
// and then write to the file by both the child as well as the
// parent processes. Check output of the file.

#include <stdio.h>
#include <unistd.h>  // For fork() and getpid()
#include <fcntl.h>   // For open()
#include <sys/types.h> // For pid_t
#include <sys/wait.h>  // For wait()
#include <string.h>  // For strlen()
int main() {
    int fd;
    int pid;
    char fileName[250];
    char dataToWrite[1000];
    printf("Enter the filename \n");
    fgets(fileName,sizeof(fileName),stdin);
    // Open a file, if it is not available then create new file
    fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd < 0) {
        perror("there is an error while opening file");
        return 1;
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        printf("Fork not created");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("enter a message for child process \n");
        fgets(dataToWrite,sizeof(dataToWrite),stdin);
        write(fd, dataToWrite, strlen(dataToWrite));
    } else {
         // Wait for the child process to finish
           wait(NULL);
        // Parent process
        printf("enter a message for Parent Process \n");
        fgets(dataToWrite,sizeof(dataToWrite),stdin);
        write(fd, dataToWrite, strlen(dataToWrite));

       
     
    }

    // Close the file
    close(fd);

    return 0;
}
