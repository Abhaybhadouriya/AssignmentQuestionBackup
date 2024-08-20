// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 9. Write a program to print the following information about a given file.
// a. inode
// b. number of hard links
// c. uid
// d. gid
// e. size
// f. block size
// g. number of blocks
// h. time of last access
// i. time of last modification
// j. time of last change

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


int main() {
    char fileNameAndPath[250];
    printf("Enter the file name \n");
    if (fgets(fileNameAndPath, sizeof(fileNameAndPath), stdin) == NULL) {
        perror("Error reading input");
        return 1;
    }
        // Removeing the newline character 

    fileNameAndPath[strcspn(fileNameAndPath, "\n")] = '\0';
    // file metadata are stored in a structure of type  below defined 'struct stat'
    struct stat fileStat;

    // Get file status
    if (stat(fileNameAndPath, &fileStat) < 0) {
        perror("There is an Error while getting the file status");
        return 1;
    }

    // Print file information
    printf("1 .File Name is : %s\n", fileNameAndPath);
    printf("2. Inode number : %ld\n", (long)fileStat.st_ino);
    printf("3. Number of hard links of giver file is : %ld\n", (long)fileStat.st_nlink);
    printf("4. User ID (UID) : %d\n", fileStat.st_uid);
    printf("5. Group ID (GID) : %d\n", fileStat.st_gid);
    printf("6. Size of the File in Bytes: %ld bytes\n", (long)fileStat.st_size);
    printf("7. Total Block size: %ld bytes\n", (long)fileStat.st_blksize);
    printf("8. Total Number of blocks: %ld\n", (long)fileStat.st_blocks);
    // ctime() function is used to convert the time to a human readable format
    printf("9. Last accessed at: %s", ctime(&fileStat.st_atime));
    printf("10. Last modified at : %s", ctime(&fileStat.st_mtime));
    printf("11. Last changed at: %s", ctime(&fileStat.st_ctime));

    return 0;
}
