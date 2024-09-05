// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 11. Write a program to open a file, duplicate the file descriptor and append the file with both the
// descriptors and check whether the file is updated properly or not.
// a. use dup
// b. use dup2
// c. use fcntl
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main() {
    // Defining the name and address of the file 
    char fileAdd[]="testfile_Q11.txt";

    // open() function needed file name and address
    // access control flag
    // O_WRONLY = open file for write only access
    // O_APPEND = open in append mode only - data is added at the end of the file
    // O_CREAT =  creat file if not exist - 
    // O_EXCL =  fail to create a file if already exist 
    // O_RDONLY = open in only read mode
    // O_RDWR =  for reading and writing both
    // O_TRUNC = if file is there then open it and truncate the lenght to 0
    // O_NONBLOCK = open in non-blocking mode - used with pipes and device file.
    // O_SYNC = write to files are syncronised- write phycisally written to disk before write call returns
    // O_DSYNC = file data is syncronized not metadata. focus only writing actual fata
    // O_NOFOLLOW = do not follow symbolic links
    // O_CLOEXEC = close file descriptor when executing new program - it ensure FD is not inherited by child process 
    // O_TMPFILE = create a temp file that do not linked to any directory - it delete automatically
    // O_DIRECTORY = open only if path refer to directory
    // O_NOCTTY = if file is terminal device do not make it the contronlling terminal for process
    // , 777,555,456 these are the permissions
    // open() takes address, controll flag and permission
    // and return File descriptor 
    // file descriptor is a non negative int value refer to the 
    // open file of an running process
    // normally there are below File Descriptors by defaults
    // these three standard file descriptors that are automatically opened for each process
        // 0: Standard Input (stdin) – Used for reading input.
        // 1: Standard Output (stdout) – Used for writing output.
        // 2: Standard Error (stderr) – Used for writing error messages.
    // now after opening new file fd will point to 3 and 4 and so on .....
    int fd = open( fileAdd,O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // if fd is smaller than 0 means file is not able to open
    //perror() print error message related to system call and library func
    //exit() terminate program and provide an exit status
    //   1.EXIT_FAILURE - internally value is 1 (non zero)
    //   2.EXIT_SUCCESS - represent 0 - means success
    if (fd < 0) { perror("open"); exit(EXIT_FAILURE); }

    // dup(fd) - LL file management - provide ability to create multiple reference to same file or resource
    // dup2(fd,10) - unlike dup which return smallest available FD and 
    // dup2 allow you to specify the exact file descriptor number you want to use 
    // on faliure return -1 otherwise return new fd which is pointing to same FD as oldFD
    int fd_dup = dup(fd);
    int fd_dup2 = dup2(fd, 10);
    // fcntl( fd cmd arg)
    // it is used to provide various control operations on FD, duplicating FD,Changing file status flags, and obtaining info about FD
    // there are some comman cmd 
    // 1. F_DUPED - FD ki smallesst available FD number jo equall or greater ho specified value ka usko duplicate karo
    // 2. F_DUPFD_CLOEXEC - same as above and also FD_CLOEXEC flag set
    // 3. F_GETFD - get FD flags
    // 4. F_SETFD - set FD flag
    // 5. F_GETFL - get file status flag (O_RDONLY,O_WRONLY)
    // 6. F_SETFL - set file status
    // 7. F_GETLK - get info about file lock
    // 8. F_SETLK - set or remove file lock
    // 9. F_SETLKW - set or remove file lock or wait if necessary
    // 10. F_GETOWN - get procrss id or procress group ID that will receice SIGURG signals
    // 11. F_SETOWN -  set process or Process group ID 
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);

    // Writing with different descriptors
    // write(fd,buff[],size);
    // this method is used to write in a file using FD 
    // and 3rd arg is provided to specify the length og data we are going to write

    write(fd, "Original data\n", 14);
    write(fd_dup, "dup data \n", 10);
    write(fd_dup2, "dup2 data\n", 10);
    write(fd_fcntl, "fcntl data\n", 11);
    // it is used to close the FD and release all the lock and resource which being used by FD
    // on sucecss return 0 else 1 
    close(fd); close(fd_dup); close(fd_dup2); close(fd_fcntl);

    // Check the content of the file
    // again opening file with readonly flag and default permissions and if file exist then update  fd
    fd = open(fileAdd, O_RDONLY);
    // declare buffer to store the data
    char buffer[1024];
    // ssize_t - it is a signet integer which repreasent the size of block or the number of bytes reads or writter
    // here we are reading data from fd and copies to buffer 
    //  buffer is block of memory that we have allotted but 
    // after reading fd we need to add null pointer manually to the end
    // we specify -1 in the end to store null pointer 
    // last arg of read() tells us how many maximum bytes to read
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    // if ssize_t return less than 0 then it means there is an error
    // close fd and exit the program  with exit code
    if (bytes_read < 0) { perror("read"); close(fd); exit(EXIT_FAILURE); }
    // set the null pointer to the end wafter how muhc bytes we have been read
    buffer[bytes_read] = '\0';
    // just print it
    printf("File content:\n%s", buffer);
    // close fd
    close(fd);
    return 0;
}
