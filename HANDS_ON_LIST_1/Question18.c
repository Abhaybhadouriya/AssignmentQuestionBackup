// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 18. Write a program to perform Record locking.
// a. Implement write lock
// b. Implement read lock
// Create three records in a file. Whenever you access a particular record, first lock it then modify/access
// to avoid race condition 


#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILE_PATH "./Question18.txt"
#define RECORD_SIZE 16

int max(int a, int b) {
    return (a > b) ? a : b;
}
void increment_and_format(char *str) {
    int number = atoi(str);
    number++;
    snprintf(str, RECORD_SIZE-1, "%d", number);
    int len = strlen(str);
    int zeros_to_add = 15 - len;
    if (zeros_to_add > 0) {
        memmove(str + zeros_to_add, str, len + 1); 
        memset(str, '0', zeros_to_add);
    }
}
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
void createNewArr(char *str,char *src,int from , int end){
    int j=0;
     for(int i=from;i<end;i++){
        str[j++]=src[i];
     }
}
void writelock(int fd,int rNo){
    off_t offset = rNo*(RECORD_SIZE-1);
    size_t size = RECORD_SIZE-1;
    setlock(fd,F_WRLCK,offset,size);
    printf("Locking the record file %d\n",rNo);
    char buff[rNo*RECORD_SIZE];
    char newBuff[RECORD_SIZE];
    ssize_t bytesReaded =  read(fd,buff,sizeof(buff)-1);
    if (bytesReaded == 0) {
        printf("Record is empty. Initializing with 0.\n");
        memset(buff,'0',sizeof(buff));
    }else{
     createNewArr(newBuff,buff,max(0,((rNo-1)*RECORD_SIZE-(rNo-2))),(RECORD_SIZE*rNo-rNo));
    }
    newBuff[RECORD_SIZE]='\0';
    int number = atoi(newBuff);
    printf("Current entry in Record no : %d  is  : %d\n",rNo,number);
    printf("Press enter to update the Record no :%d \n",rNo);
    getchar();
    getchar();
    number++;
    increment_and_format(newBuff);
    if(bytesReaded>0) lseek(fd,max(0,((rNo-1)*RECORD_SIZE-(rNo-1))),SEEK_SET);
    else   lseek(fd,0,SEEK_SET);
    write(fd,newBuff,strlen(newBuff));
    printf("Your Record is updated: %d\nReleasing the lock on Record no : %d\n",number,rNo);
    releaselock(fd,offset,size);
}
void readlock(int fd,int rNo){
    off_t offset = (rNo-1)*(RECORD_SIZE-1);
    size_t size = RECORD_SIZE-1;
     setlock(fd,F_RDLCK,offset,size);
     printf("Locking the record file  : %d in reading mode\n",rNo);
     char buff[rNo*RECORD_SIZE];
    char newBuff[RECORD_SIZE];
     printf("Hit Enter to get the data of current record \n");
     getchar();
     getchar();
     lseek(fd,offset,SEEK_SET);
     ssize_t bytes_read= read(fd,buff,sizeof(buff)-1);
     
     buff[RECORD_SIZE-1]='\0';
     printf("Data of current Record : %d is : %d\n",rNo,atoi(buff));
     printf("Now Releasing the lock on %d Record\n",rNo);

    releaselock(fd,offset,size);
}

int selectRecord(){
    int select;
    printf("Enter the record no you want to go with\n1\n2\n3\n");
    scanf("%d",&select);
    return select;
}
int main(){
    int fd = open(FILE_PATH,O_RDWR,0666);
    if(fd<0) {
        perror("open");
        exit(1);// fail to open
    }
    int choice;
    printf("Enter your choice\n1). Write Mode\n2). Read Mode\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: writelock(fd,selectRecord()); break;
    case 2: readlock(fd,selectRecord()); break;
    default: break;
    }

    close(fd);
    return 0;
}