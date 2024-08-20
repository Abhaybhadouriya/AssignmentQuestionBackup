#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Argument passed by you : %s!\n", argv[1]);
    } else {
        printf("No argument is passed!\n");
    }
    return 0;
}
