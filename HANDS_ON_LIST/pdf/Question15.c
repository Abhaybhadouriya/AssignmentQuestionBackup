// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 15. Write a program to display the environmental variable of the user (use environ).
#include <stdio.h>


// environ is a global variable provided by the system
// it points to an array of string 
// extern keyword used to declare the variable without defining it
// it indicate that 'environ' is a global variable defined in another source file
// so store the reference of that file in our file
// it will link it during compile time 
extern char **environ; // Declare the external variable environ

int main() {

    printf("Environmental Variables:\n");
    // declaring and initilising a Pointer to the environment variable list
    // Iterate through the environment variable list using for loop
    // Print each environment variable 
    // Move to the next environment variable till it is available
    for (char **env = environ; *env; ++env) {
        printf("%s\n", *env);
    }

    return 0;
}
