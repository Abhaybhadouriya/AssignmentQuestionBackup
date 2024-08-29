// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
// bytes (use lseek) and write again 10 bytes.
// a. check the return value of lseek
// b. open the file with od and check the empty spaces in between the data.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd;
    //ssize_t is signed data type used to track record 
    //number of bytes written and readed by system call "read()" or "write()"
    ssize_t bytes_written;
    // off_t is data type used for file sie and offset
    off_t offset;

    const char *data1 = "TEMPDATA01";  // 10 bytes of data we will add first
    const char *data2 = "TEMPDATA02";  // 10 bytes of data we will add later
    char fileName[250];
    printf("Enter the file name \n");
    if(fgets(fileName,sizeof(fileName),stdin)== NULL) {
        perror("Error  while reading input");
        return 1;
    }
    // removing the newline character 
    fileName[strcspn(fileName ,"\n")] = '\0';
    // Open the file in read and write mode
    // or  create  new file if it does not exist
    // and truncate to 0 length
    fd = open(fileName, O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (fd < 0) {
        perror("Error while opening the file");
        return 1;
    }

    const char *tempData = "ABCDEF  GHIJKLMN  OPQRSTUVWXY  Zabcdefghijklm  nopqrstuvw  xyz";
    // writing temp data in so while using lseek no error occur in file
    bytes_written = write(fd, tempData, strlen(tempData));
    if (bytes_written < 0) {
        perror("Error while writing Temp data to the file");
        close(fd);
        return 1;
    }

    // now just setting the cuurent point to middle of data 
    // otherwise if i directly use lseek on empty position 
    // it will print unknown char in between that causes file error
    offset = lseek(fd, -30, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("There is an Error while using lseek");
        // close FD and exit with failure code
        close(fd);
        return 1;
    }

    // Now write the first 10 bytes to the new file
    // fd - targeted file
    // data1 - buffer data we are going to write
    // 10 - size of bytes count
    bytes_written = write(fd, data1, 10);
    if (bytes_written < 0) {
        perror("Error writing to the file");
        close(fd);
        return 1;
    }

    // Move the file pointer by 10 bytes using lseek()
    // lseek() uses whence arg to indicate how the offset argu should be interpreted
    //  when changing the file pointer position
    // 1. SEEK_SET - offset is set relative to starting of file
    //    lseek(fd,10,SEEK_SET) - move file pointer to 10 bytes from start of the file
    // 2. SEEK_CUR - offset is applied to current file position
    //    offset can be mode forward or backward from current position
    //    lseek(fd, -5, SEEK_CUR) // move file pointer 5 bytes backward from current position
    // 3. SEEK_END - offset is applied to end of the file. file pointer is moved to a position
    //    'offset' bytes from the end of file . it often used for appendinf data to a file
    //    lseek(fd,0,SEEK_END) // file pointer is moved to end of the file


    // here we are just moving the file pointer to 10th position from start
    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("There is an Error while using lseek");
        // close FD and exit with failure code
        close(fd);
        return 1;
    }
    // it will print the new position of offset
    printf("lseek() returned the new position  : %ld\n", (long)offset);

    // now again write the new 10 bytes in files
    // on success it will return the no bytes it writes
    // failure it will return -1
    bytes_written = write(fd, data2, 10);
    if (bytes_written < 0) {
        perror("Error writing to the file");
        
        // error caused so just close the FD and
        //  close the program with exit code 1(error)
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    // Run the 'od' command to check the file contents
    char cmd[300];
    snprintf(cmd, sizeof(cmd), "od -c %s", fileName);
    printf("File Data:\n");
    
    return 0;
}
