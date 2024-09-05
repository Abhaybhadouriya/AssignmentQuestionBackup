// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
//17. Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.

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
    char buff[250];
    ssize_t bytesReaded =  read(fd,buff,sizeof(buff)-1);
    // if data present the truncate the file
    ftruncate(fd,0);
    lseek(fd,0,SEEK_SET);
    snprintf(buff,sizeof(buff),"%d",0);
    write(fd,buff,strlen(buff));
    printf("Ticket Number is stored to 0.\n");
    releaselock(fd,offset,size);
}
int main(){
    int fd = open("./Question17.txt",O_RDWR,0666);
    if(fd<0) {
        perror("open");
        exit(1);// fail to open
    }
    int choice;
    writelock(fd,100,0); 
    close(fd);
    return 0;
}