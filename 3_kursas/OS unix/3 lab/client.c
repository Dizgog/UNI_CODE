#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 12344
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    while (1) {
        char message[BUFFER_SIZE];
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);

        // Send the message to the server
        send(client_socket, message, strlen(message), 0);

        // Receive the server's response
        memset(message, 0, sizeof(message));
        recv(client_socket, message, sizeof(message), 0);
        printf("Server response: %s\n", message);
    }
    shutdown(client_socket, SHUT_RDWR);
    close(client_socket);
    return 0;
}
