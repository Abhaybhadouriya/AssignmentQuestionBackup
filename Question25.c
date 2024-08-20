// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 25. Write a program to create three child processes. The parent should wait for a particular child (use
// waitpid system call)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // For waitpid()

int main() {
    int child1, child2, child3;

    // Create three child processes
    // child1 = fork();
    // child2 = fork();
    // child3 = fork();
    if ((child1 = fork()) == 0) {
        printf("Child 1 is running : %d\n", getpid());
        exit(0);
    }
    
   if ((child2 = fork()) == 0) {
        printf("Child 2 is running : %d\n", getpid());
        exit(0);
    }
    
    if ((child3 = fork()) == 0) {
        printf("Child 3  is running : %d\n", getpid());
        exit(0);
    }

    //  waitpid will wait for particular process
    //  and setting 0 means it will block the process untill its
    //  targeted child is executed successfully and changes its state 
    //  &status varibale hold the return status of child
    waitpid(child2, NULL, 0);
    printf("Child %d exited\n", child2);

    return 0;
}
