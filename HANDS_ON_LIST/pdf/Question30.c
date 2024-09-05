// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 30. Write a program to run a script at a specific time using a Daemon process.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

// script name which we are going to run 
#define SCRIPT_PATH "./alert.sh"
// time in hour
#define TARGET_HOUR 23
// time in minute
#define TARGET_MINUTE 06

void createDaemonProcess() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // child not created
        exit(1);
    }

    if (pid > 0) {
        // terminate parent
        exit(0);
    }

    // Set the child process as the session leader
    if (setsid() < 0) {
        // exit if session is not created on child
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);
    chdir("/");

    // Close standard input, output, and error file descriptors
    close(STDIN_FILENO);  
    close(STDOUT_FILENO); 
    close(STDERR_FILENO); 
}



int main() {
   
    // run for infinite for checking if time is there 
    int hour;
    int min;
    printf("Enter Hour in 24hour format \n");
    scanf("%d",&hour);
    printf("Enter minute \n");
    scanf("%d",&min);
     createDaemonProcess();
    while (1) {
        // getting time in UTC
        time_t now = time(NULL);
        // converting time to local machine
        struct tm *tm_info = localtime(&now);
        if (tm_info->tm_hour == hour && tm_info->tm_min == min) {
                // when time is same then just trigger the execl
                    system("/home/abhay/Desktop/handsOnList/alert.sh"); 
                    return 0;
        }
        sleep(5); 
   }
    return 0;
}
