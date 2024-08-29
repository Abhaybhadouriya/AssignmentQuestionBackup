#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

// script name which we are going to run 
#define SCRIPT_PATH "./Question26a.out"
// time in hour
#define TARGET_HOUR 22
// time in minute
#define TARGET_MINUTE 9

int main() {
    // run for infinite for checking if time is there 
    while (1) {
        // getting time in UTC
        time_t now = time(NULL);
        // converting time to local machine
        struct tm *tm_info = localtime(&now);
        if (tm_info->tm_hour == TARGET_HOUR && tm_info->tm_min == TARGET_MINUTE) {
                
                // when time is same then just trigger the execl
                execl(SCRIPT_PATH, SCRIPT_PATH, (char *)NULL);
        }
        sleep(5); 
   }
    return 0;
}
