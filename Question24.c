// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 24. Write a program to create an orphan process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();  // creating a child process using fork()

    if (pid < 0) {
        printf("There is an error while creating process using fork");
        return 1;
    } else if (pid == 0) {
        // Child
        // here we set our child sleep for few secs 
        // then let parent process complete its executation
        sleep(10);  
        printf("Child process with process ID: %d  is now became an orphan.\nAs parent process is exited.\n", getpid());
        // after parent process exited. the init process takeover the orphan and let child compele its execution
        // here in linux-Ubuntu 24.04 LTS orphan is handled by systemd 
        // please check the to check systemd process
        // pidof systemd
        printf("Parent process ID after child become orphan : %d\n", getppid());
    } else {
        // Parent
        // set parent process to sleep so our child can enter and get sleep
        // as soon child process set to sleep the parent start its execution jsut after 2 sec
        // and prints it process id and exit from execution leaving child process in sleeping state
        sleep(2);
        printf("Parent process  with process ID: %d is now exiting.\n", getpid());
        exit(0);
    }

    return 0;
}
