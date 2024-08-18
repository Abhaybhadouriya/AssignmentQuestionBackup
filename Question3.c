#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char fileName[250];  // File name buffer
    int fd; // declaring the FD
    printf("Enter the file name -  \n");
    if(fgets(fileName,sizeof(fileName),stdin)==NULL){
        perror("Error while reading filename");
        return 1;
    }

    // Create System call is used to create a new file,truncate an existing file and open file in write only mode
    // creat(pathname,mode_t mode) - mode -> it is file permission to be set when file is created. uses
    // S_IRUSER -  read permission for owner
    // S_IWUSER - write permission for owner
    // S_IXUSER - execute/search permission for owner
    // and same stand for  - S_IRGRP,S_IWGRP,S_IXGRP for group
    // and same stand for  - S_IROTH,S_IWOTH,S_IXOTH for other
    // its equivalent open is open(filename,O_CREAT | O_WRONLY | O_TRUNC, mode)
    // creat return FD
    fd = creat(fileName, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("There is an Error while creating the file.");
        return 1;
    }

    // Print the file descriptor value and name
    printf("Filename is : %s \nDescriptor  value is : %d\n",fileName ,fd);

    // Close the file descriptor
    close(fd);
    // return success code

    return 0;
}
