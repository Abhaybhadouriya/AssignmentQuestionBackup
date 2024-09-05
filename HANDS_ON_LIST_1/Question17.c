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
    printf("Locking the record file to book a ticket\n");
    char buff[250];
    ssize_t bytesReaded =  read(fd,buff,sizeof(buff)-1);
    buff[bytesReaded]='\0';
    int number = atoi(buff);
    printf("Current no of Ticket Booked : %d \n",number);
    printf("Press enter to Book Your ticket \n");
    getchar();
    getchar();
    number++;
    lseek(fd,0,SEEK_SET);
    snprintf(buff,sizeof(buff),"%d",number);
    write(fd,buff,strlen(buff));
    printf("Ticket is Booked.\nYour Ticket no : %d\n Releasing the lock",number);
    releaselock(fd,offset,size);
}
void readlock(int fd,off_t offset,size_t size){
     setlock(fd,F_RDLCK,offset,size);
     printf("Ticket record are locked in Reading mode ,\n");
     char buff[500];
     printf("Hit enter to get current no of ticket booked \n");
     getchar();
     getchar();
     lseek(fd,0,SEEK_SET);
     ssize_t bytes_read= read(fd,buff,sizeof(buff)-1);
     buff[bytes_read]='\0';
     printf("Ticket booked : \n\n%s \n",buff);
     printf("Now Releasing the lock\n");

    releaselock(fd,offset,size);
}
int main(){
    int fd = open("./Question17.txt",O_RDWR,0666);
    if(fd<0) {
        perror("open");
        exit(1);// fail to open
    }
    int choice;
    printf("Enter your choice\n1). Book Ticket (According to Question Press 1)\n2). Read Total Ticket Booked(Just to lookat total Tickets)\n");
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