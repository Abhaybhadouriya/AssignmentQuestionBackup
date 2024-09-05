// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
//20. Find out the priority of your running program. 
//    Modify the priority with nice command.

#include <stdio.h>
#include <unistd.h>
int main(){

    while(1){
        // now this will run infinatly

        sleep(1);
    }
    return 0;
}
// just run this program either back or foreground

// now to check the priority of our running program
// $ps -l -p <pid>
// entter this and it will return us below data 
//  |  abhay@abhay-pc:~/Desktop/handsOnList$ ps -l -p 12689
//  | F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
//  | 0 S  1000   12689    9069  0  80   0 -   638 hrtime pts/2    00:00:00 a.out

// PRI - PRiority
// NI : nice value  (default val is 0)

// now stop program and change the nice value
// nice value change on starting 
// use 'nice' command

// $ nice -n 10 ./prog_name

// if you want to change the nice value while running 
// use 'renice' command

// renice -n 25 -p <pid>
