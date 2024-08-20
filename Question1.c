// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 1. Create the following types of a files using (i) shell command (ii) system call
// a. soft link (symlink system call)
// b. hard link (link system call)
// c. FIFO (mkfifo Library Function or mknod system call)

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // declaring the names of files
    char *myOriginalFile = "MyOriginalFile.txt";
    char *symLinkFile = "mySymLinkFile";
    char *hardLinkFile = "myHardLinkFile";
    char *fifoFile = "myFifoFile";

    // creating the file with name "MyOriginalFile.txt"  which an original file for all linker links
    // FILE *fp is file pointer to a file object
    // fopen return the pointer to a FILE structure that represent the open file stream on success else null
    // 
    FILE *fp = fopen(myOriginalFile, "w");
    if (!fp) {
        perror("Error creating original file");
        return 1;
    }

    // used to write formatted O/P to file stream.
    // fprintf(File *stream, const char *format, ...)
    // 1st arg - file pointer to file
    // 2nd arg - formate string
    // 3rd - additional argument for format 
    fprintf(fp, "This is out original file which is used for linking purpose.\n");
    // close the file pointer
    fclose(fp);

    // int symlink(const char *target, const char *linkpath);
    //  it will create new file that points to target file
    // if original file is deleted, moved, renamed the symbolic link may become "broken"
    // there are there error
    // 1. EEXIST  = sym link already exist
    // 2. ENOENT  = target file not exist
    // 3. EACCES  = parmission denied 
    if (symlink(myOriginalFile, symLinkFile) == -1) {
        perror("we have encountered and Error  while creating symbolic link");
        return 1;
    }
    printf("Symbolic link created: %s -> %s\n", symLinkFile, myOriginalFile);

    // hardlink is just a additional entry that points to the same original file inode
    // both are same and sharing the same data block changes made to one file will reflext to another
    // all there error are same but haere one error we can see
    // 4. EXDEV -  target and files are on different file system  as we cannot create hard link on different file system
    if (link(myOriginalFile, hardLinkFile) == -1) {
        perror("we have encountered and Error  while creating hard link");
        return 1;
    }
    
    printf("Hard link created: %s -> %s\n", hardLinkFile, myOriginalFile);

    // Fifo is IPC 
    // mkfifo() takes 2 argument path and permissions
    if (mkfifo(fifoFile, 0666) == -1) {
        perror("we have encountered and Error  while creating FIFO");
        return 1;
    }
    printf("Fifo file is : %s\n",fifoFile);

    return 0;
}
