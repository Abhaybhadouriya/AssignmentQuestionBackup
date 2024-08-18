#include <stdio.h>
#include <unistd.h>

int main() {
    // run this program in backgroud using below command


    // './Question2 &' 
    // 'ps aux | grep Question2'

    // now to explore the PID
    // '  cd /proc/<process id of running process> '


    // in this directory we can also get the detailed info about the process
    // cat /proc/<pid>/cmdline - the cmd arg passed to process
    // cat /proc/<PID>/status  -  info about the process status, pid, parent pid, etc
    // ls -l /proc/<PID>/fd -  list of all opened files
    // cat /proc/<PID>/maps - memory mapping of program
    // ls -l /proc/<PID>/cwd - display process currently working directory
    // cat /proc/<PID>/environ | tr '\0' '\n'  -  file contains the environment variable passed to process
    // ls -l /proc/<PID>/exe 
    // cat /proc/<PID>/stat -   single line space seprated values representing the process status and performance
    // cat /proc/<PID>/limits - diplay limit imposed on process (max open files, memory usage)
    // cat /proc/<PID>/sched - it display scheduling info  - such as number of voluntary and involuntary context switches
    // run this infinitely
    while (1) {
        // sleeping program for every 2-2 sec to utilize the cpu resources
        sleep(1);
    }
    return 0;
}
