#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    char fileName[250];  // Replace with your file name
    int fd;
    printf("Enter the filename \n");
    if(fgets(fileName,sizeof(fileName),stdin)== NULL) {
        perror("Error  while reading input");
        return 1;
    }
    // O_CREAT Create the file if does not exist, always use O_RDWR to ensure
    // that a file can be created if it does not exist
    // O_EXCL - prevent from overwritng the file   
    fd = open(fileName, O_RDWR | O_CREAT | O_EXCL, 0666);
    // now check the fd if it able to open or not
    if (fd < 0) {

        // here we compare the error
        // by compare errno with  EEXIST flag 
        if (errno == EEXIST) {
            printf("File is already exists.\nO_EXCL flag prevented opening the file.\n.Please enter different name\n");
        } else {
            perror("Error while opening the file");
        }
        // return error code
        return 1;
    }
    
    printf("Congratulations: Your File is opened successfully with O_EXCL flag.\n");
    // Close the file
    close(fd);
    // return success code
    return 0;
}
