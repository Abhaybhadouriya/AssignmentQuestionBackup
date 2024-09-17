/*
============================================================================================
File Name : 34b.c
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
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket_ptr) {
    int client_socket = *((int *)client_socket_ptr);
    char buffer[BUFFER_SIZE] = {0};
    int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
    if (bytes_read > 0) {
        printf("Client message: %s\n", buffer);
        send(client_socket, "Message received", 17, 0);
    }
    close(client_socket);
    free(client_socket_ptr);
    return NULL;
}

int main() {
    int server_fd, *client_socket_ptr;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t thread_id;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    while (1) {
        int client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;
        pthread_create(&thread_id, NULL, handle_client, client_socket_ptr);
        pthread_detach(thread_id);  // Detach the thread to avoid joining
        
    }
    close(server_fd);
    return 0;
}
