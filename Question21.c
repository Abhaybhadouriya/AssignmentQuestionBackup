// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 21. Write a program, call fork and print the parent and child process id.
#include <stdio.h>
#include <unistd.h>  
int main() {
    // Create a new process
    int pid = fork();

    if (pid < 0){
        printf("Fork is failed to create\n");
        return 1;
    } else if (pid == 0) {
        // Child process created
        printf("Child process. Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    } else {
        // Parent process
        printf("This is the parent process. Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}
