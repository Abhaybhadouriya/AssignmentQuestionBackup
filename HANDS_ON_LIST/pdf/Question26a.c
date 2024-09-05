// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 26. Write a program to execute an executable program.
// a. use some executable program
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Argument passed by you : %s!\n", argv[1]);
    } else {
        printf("No argument is passed!\n");
    }
    return 0;
}
