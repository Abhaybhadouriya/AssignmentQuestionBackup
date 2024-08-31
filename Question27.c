// Roll no :- MT2024003
// Name :- Abhay Bhadouriya 
//27. Write a program to execute ls -Rl by the following system calls
// a. execl
// b. execlp
// c. execle
// d. execv
// e. execvp


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // 1. Using execl
    // Syntax: int execl(path, filename ..., NULL)
    //in execl() 1st argument is path to file
    //           2nd argument is name of file
    //           3rd argument is argument which is needed to be passed
    // in this we need to provide full executable path
    // it does not use the PATh enviromant variable to locate the executable
    // it replace the current process image with a new process image. the current 
    // process will completely replaced. 
    printf("\n\n--------------------------------------------------------\n\n");
    printf("Executing excel() Function \n");
    printf("\n\n--------------------------------------------------------\n\n");
    if (fork() == 0)     execl("/bin/ls", "ls", "-Rl", NULL);
    else     wait(NULL); // Wait for the child process to finish
    

    // 2. Using execlp
    // int execlp(file, *arg0, ...,NULL)
    // it  searches file in the directory listed in the PATH envrionment variable
    // argument list must be terminated by a 'NULL' 
    // is also replaces process image
    printf("\n\n--------------------------------------------------------\n\n");
    printf("Executing execlp() Function \n");
    printf("\n\n--------------------------------------------------------\n\n");
    if (fork() == 0) execlp("ls", "ls", "-Rl", NULL);
    else wait(NULL); // Wait for the child process to finish
    

    // 3. Using execle
    // it is also same as execl but it allows specifying a custom
    // environment list for the new process. environment list is 
    // passed as an array of strings, ending with a 'NULL' pointer
    // envp - array of environment variavles for the new process
    printf("\n\n--------------------------------------------------------\n\n");
       printf("Executing execle() Function \n");
       printf("\n\n--------------------------------------------------------\n\n");
    if (fork() == 0) {
        char *envp[] = {NULL}; // Passing an empty environment
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
    } else wait(NULL); // Wait for the child process to finish

    // 4. Using execv
    // execv execute a program specified by path with arguments passed as an array of strings
    // the array must be terminated by a NULL pointer
    // path to executable file
    // argv - an array of string representing the command line argumets for exectubale
    // first element should be the name of the program itself
    printf("\n\n--------------------------------------------------------\n\n");
   printf("Executing execv() Function \n");    
   printf("\n\n--------------------------------------------------------\n\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
    } else     wait(NULL); // Wait for the child process to finish
    

    // 5. Using execvp
    // it is similer to execv but it searches for the executbale file in the directories listed
    // in the 'PATH' envrionment variable
    // the argument are passed as an array of strings
    // the name of file to execute it searched in the directories  specified in path
    // args should be in array of string
    printf("\n\n--------------------------------------------------------\n\n");
   printf("Executing execvp() Function \n");
   printf("\n\n--------------------------------------------------------\n\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
    } else {
        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
