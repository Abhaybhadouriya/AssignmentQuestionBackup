// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
// verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    //it is datatype used to represent a set of FD
    // it allow use to track a FD to monitor for an activity. FD ie - such as socket,pipes or standard input/output
    fd_set readfds;
    // it is used to represent time intervel
    // first value define seconds and second value define microsecond
    // here {10,0} it is 10 sec and 0 ms
    struct timeval timeout = {10, 0};  // 10 seconds timeout

    // this function used to clear the fd_set and reset it to empty
    FD_ZERO(&readfds);
    //using this function will set fd to fd_set
    // there are 3 FD 
    //     1. STDIN_FILENO (0){stdin} - take input from keyboard or pipe etc
    //     2. STDOUT_FILENO (1){stdout} -  write o/p
    //     3. STDERR_FILENO (2){stderr} - for error messages writing 
    // by setting sdtin to set now program will understood that we want to moniter the input
    FD_SET(STDIN_FILENO, &readfds);


    printf("Waiting for input on STDIN for 10 seconds...\n");
   
    // select syntex are alike
    // select(nfds,readfd,writefd,exceptfd,timeinterval)
    // STDIN_FILENO - {select() requires the highest FD number +1 because FDs are zero based indecies
    // like if want to moniter 0 index then we need to specify 1 as nfds }
    // timeout -  it will wait till the time we mentioned
    // if data available before time mentioned then it will return positive value
    // if no data is given it return 0
    // any error occur  then it will return -1
    int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select()");
    } else if (retval == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        printf("Data is available on STDIN.\n");
    }

    return 0;
}
