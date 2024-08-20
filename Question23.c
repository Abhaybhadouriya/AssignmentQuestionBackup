#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // For wait()

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(EXIT_SUCCESS);  // Exit immediately, becoming a zombie
    } else {
        // Parent process
        printf("Parent process (PID: %d) will now sleep...\n", getpid());
        printf("Child process (PID: %d) will become a zombie...\n", pid);

        // Sleep for 30 seconds to allow observation of the zombie state
        sleep(30);

        // Optionally, the parent process can clean up by calling wait()
        // wait(NULL);

        printf("Parent process (PID: %d) is exiting...\n", getpid());
    }

    return 0;
}
