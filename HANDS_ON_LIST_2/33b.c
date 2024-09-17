/*
============================================================================================
File Name : 33b.c
Author : Abhay bhadouriya
Roll No : MT2024003
Description : 
33. Write a program to communicate between two machines using socket.

Data : 17/09/2024
============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    // Create socket file descriptor
    sock = socket(AF_INET, SOCK_STREAM, 0);
    // Define the server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Convert IPv4 address from text to binary form
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    // Connect to the server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    // Send message to the server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);
    // Close the socket
    close(sock);
    
    return 0;
}
