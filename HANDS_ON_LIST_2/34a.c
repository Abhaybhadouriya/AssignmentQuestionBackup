/*
============================================================================================
File Name : 34a.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 
34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
    if (bytes_read > 0) {
        printf("Client message: %s\n", buffer);
        send(client_socket, "Message received", 17, 0);
    }
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pid_t pid;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        pid = fork();
        if (pid == 0) {
            // Child process
            close(server_fd); // Child does not need this
            handle_client(client_socket);
            exit(0);
        } else {
            close(client_socket); // Parent does not need this
        }

        // Clean up zombie processes
        while (waitpid(-1, NULL, WNOHANG) > 0);
    }

    close(server_fd);
    return 0;
}
