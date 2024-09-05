// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 23. Write a program to create a Zombie state of the running program.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // For wait()

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("There is an error in fork - process is not created");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process  with process ID: %d is completed now exiting.\n", getpid());
        exit(0);  // Exit immediately, becoming a zombie
    } else {
        // Parent process
        printf("Parent process with Process ID: %d is running will now sleep.\n", getpid());
        // Sleep for 30 seconds to check the zombie state in terminal 
        // run this process FG or BG use below command to check zombie process
        // $ps aux | grep Z
        // here parent is sleeping for 30 sec without calling wait()
        // so child become zombie because it is exited but still not yet acknowledged by parent
        sleep(30);

       
        printf("Parent process with process ID: %d is exiting.\n", getpid());
    }

    return 0;
}

// zombie process is a process that is completed but still has an entry in process table.
// this happen due to parent process did not use 'wait()' or 'waitpid()' function to check exit status of child
// 