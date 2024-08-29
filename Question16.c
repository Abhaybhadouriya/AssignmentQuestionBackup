// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 6. Write a program to perform mandatory locking.
// a. Implement write lock
// b. Implement read lock

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void releaselock(int fd,off_t offset, size_t size){
    struct flock lock;
    lock.l_type=F_UNLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=offset;
    lock.l_len = size;
    fcntl(fd,F_SETLK,&lock);

}
void setlock(int fd, int type,off_t offset,size_t size){
    struct flock lock;
    lock.l_type= type;
    lock.l_whence=SEEK_SET;
    lock.l_start=offset;
    lock.l_len = size;
    fcntl(fd,F_SETLKW,&lock);
}
void writelock(int fd,off_t offset,size_t size){
    setlock(fd,F_WRLCK,offset,size);
    printf("file is locked in write mode\n");
    char *data = "THE DATA IS WRITTEN BY WRITELOCK FUNCTION DEFINED BY ABHAY";
    printf("Press enter to write \n");
    getchar();
    getchar();
    write(fd,data,strlen(data));
    printf("Write operation done. Releasing the lock");
    releaselock(fd,offset,size);
}
void readlock(int fd,off_t offset,size_t size){
     setlock(fd,F_RDLCK,offset,size);
     printf("File is locked in Reading mode \n");
     char buff[500];
     printf("Hit enter to read the file \n");
     getchar();
     getchar();
     lseek(fd,0,SEEK_SET);
     ssize_t bytes_read= read(fd,buff,sizeof(buff)-1);
     buff[bytes_read]='\0';
     printf("Data Read from file : \n\n%s \n",buff);
     
     printf("Now Releasing the lock\n");

    releaselock(fd,offset,size);
}
int main(){
    int fd = open("./Question16.txt",O_RDWR,0666);
    if(fd<0) {
        perror("open");
        exit(1);// fail to open
    }
    int choice;
    printf("Enter your choice\n1).Write lock\n2).Read lock");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: writelock(fd,100,0); break;
    case 2: readlock(fd,100,0); break;
    default: break;
    }

    close(fd);
    return 0;
}