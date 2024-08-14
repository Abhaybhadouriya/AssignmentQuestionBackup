#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to print the file type
void printFileType(struct stat mode) {
    if (S_ISREG(mode.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(mode.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(mode.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(mode.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(mode.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(mode.st_mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISSOCK(mode.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
   
}

int main() {
  
    printf("Enter the file name with path \nor if file is in same directory just enter the name of file. \nFile name should be less than 255 char\n");
    char fileName[255];
    gets(fileName);
    struct stat file_stat;

    // Get file status
    // stat() function is used to obtain info about a file.
    // it fills struct stat
    // return on success 0 else 1
    // internal structure of struct stat is look like this
    //     struct stat {
    //     dev_t     st_dev;     /* Device ID of the file */
    //     ino_t     st_ino;     /* Inode number */
    //     mode_t    st_mode;    /* File type and mode (permissions) */
    //     nlink_t   st_nlink;   /* Number of hard links */
    //     uid_t     st_uid;     /* User ID of the owner */
    //     gid_t     st_gid;     /* Group ID of the owner */
    //     dev_t     st_rdev;    /* Device ID (if file is character or block special) */
    //     off_t     st_size;    /* Total size of the file in bytes */
    //     blksize_t st_blksize; /* Block size for filesystem I/O */
    //     blkcnt_t  st_blocks;  /* Number of 512-byte blocks allocated */
    //     time_t    st_atime;   /* Time of last access */
    //     time_t    st_mtime;   /* Time of last modification */
    //     time_t    st_ctime;   /* Time of last status change */
    // };
    if (stat(fileName, &file_stat) != 0) {
        perror("stat");
        return 1;
    }

    // Print file type
    printFileType(file_stat);

    return 0;
}
