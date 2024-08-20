// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 12. Write a program to find out the opening mode of a file. Use fcntl.
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void printFileMode(int flags) {
    // Check the access mode (O_RDONLY, O_WRONLY, O_RDWR)
    // O_ACCMODE is a bitmask , we use it to exrtact the access mode from flags 
    // O_ACCMODE is only mask out and extract accessmode (read ,write , read/writes)
    // for other flags we need to AND them with flag 
    int accessMode = flags & O_ACCMODE;
    if (accessMode == O_RDONLY) {
        printf("O_RDONLY Flag : File is opened in read-only mode.\n");
    } 
    else if (accessMode == O_WRONLY) {
        printf("O_WRONLY FLAG : File is opened in write-only mode.\n");
    } 
    else if (accessMode == O_RDWR) {
        printf("O_RDWR Flag : File is opened in read-write mode.\n");
    } 
    else {
        printf("Unknown access mode.\n");
    }
    
    // printf("%d \n",flags);
    //  printf("%d \n",O_APPEND);
    

    // Check additional flags
    // here other flags are needed to be AND with FLAGs(O_APPEND etc) to check
    // these flas are appended to the last are not the part of access mode of file 
    if (flags & O_APPEND) {
        printf("O_APPEND is set: Writes will append to the end of the file.\n");
    }
    if (flags & O_NONBLOCK) {
        printf("O_NONBLOCK is set: Non-blocking mode is enabled.\n");
    }
    if (flags & O_SYNC) {
        printf("O_SYNC is set: Writes are synchronized.\n");
    }
}

int main() {
    char fileAdd[]="testfile_Q12.txt";
    // Open a file with specific flags
    // open file with write and read only and append flag 
    // and adding O_CREAT flag if file not exist
    int fd = open(fileAdd, O_WRONLY | O_APPEND| O_CREAT, 0777);
    // if file not open then exit program
    if (fd < 0) {
        perror("Error while opening file");
        return 1;
    }

    // Use fcntl to get the file status flags
    // when we pass FD and F_GETFL parameter 
    // fcntal return us the flag is currently is being used by FD
    int flags = fcntl(fd, F_GETFL);
    // report error if any error found
    if (flags < 0) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }


    printFileMode(flags);

    // Close the file descriptor
    close(fd);
    return 0;
}
