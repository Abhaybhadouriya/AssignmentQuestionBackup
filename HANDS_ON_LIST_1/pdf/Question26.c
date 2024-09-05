// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 26. Write a program to execute an executable program.
// a. use some executable program
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
 
  
    int pid1, pid2;
    int status;

    // i need to create 2 different child
    // to run execl because it will replace the current process image with new image 
    // so we will just create 2 new child processes to do this work
    if ((pid1 = fork())== 0) {
        // Child process 1
        //in execl() 1st argument is path to file
        //           2nd argument is name of file
        //           3rd argument is argument which is needed to be passed
        printf("Running program without arguments\n");
        execl("./Question26a.out", "./Question26a.out", NULL);
    }
   
    if ((pid2 = fork()) == 0) {
        // Child process 2
        sleep(1);
    printf("Running program with arguments\n");
    execl("./Question26a.out", "./Question26a.out", "Abhay", NULL);
    }
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    printf("Both child processes have finished.\nAnd executed both program with or without argument.\n");
    return 0;
}
