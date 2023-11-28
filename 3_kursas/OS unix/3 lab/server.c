#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 12344
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_sockets[MAX_CLIENTS], max_clients = MAX_CLIENTS;
    struct sockaddr_in server_address, client_address;
    fd_set readfds;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Initialize client sockets
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        client_sockets[i] = 0;
    }

    while (1) {
        char message[BUFFER_SIZE];
        FD_ZERO(&readfds);
        FD_SET(server_socket, &readfds);
        int max_sd = server_socket;
        

        // Add child sockets to set
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            int sd = client_sockets[i];

            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            if (sd > max_sd) {
                max_sd = sd;
            }
        
        }

        // Wait for activity on any of the sockets
        if (select(max_sd + 1, &readfds, NULL, NULL, NULL) == -1) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // Check for incoming connection
        if (FD_ISSET(server_socket, &readfds)) {
            int new_socket;

            socklen_t addrlen = sizeof(client_address);
            if ((new_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&addrlen)) == -1) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Add new socket to array of sockets
            for (int i = 0; i < MAX_CLIENTS; ++i) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    printf("New connection, socket fd is %d, ip is : %s, port : %d\n",
                           new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    break;
                }
            }
        }

        //     if (FD_ISSET(STDIN_FILENO, &readfds)) {
        //     char shutdown_command[50];
        //     fgets(shutdown_command, sizeof(shutdown_command), stdin);
        //     if (strcmp(shutdown_command, "shutdown") == 0) {
        //         printf("Server shutting down...\n");
        //         close(server_socket);
        //         for (int i = 0; i < MAX_CLIENTS; ++i) {
        //             if (client_sockets[i] > 0) {
        //                 close(client_sockets[i]);
        //             }
        //         }
        //         exit(EXIT_SUCCESS);
        //     }
        // }

        // Handle client interactions
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            int sd = client_sockets[i];

            if (FD_ISSET(sd, &readfds)) {
                char buffer[BUFFER_SIZE];
                int valread;

                if ((valread = read(sd, buffer, sizeof(buffer))) == 0) {
                    // Client disconnected
                    socklen_t addrlen = sizeof(client_address);
                    getpeername(sd, (struct sockaddr*)&client_address, (socklen_t*)&addrlen);
                    printf("Host disconnected, ip %s, port %d\n",
                           inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    close(sd);
                    client_sockets[i] = 0;
                } else {
                    // Echo received message back to the client
                    buffer[valread] = '\0';
                    write(sd, buffer, strlen(buffer));
                    printf("Message sent: %s\n", buffer);
                }
            }
        }
    }
    shutdown(server_socket, SHUT_RDWR);
    close(server_socket);
    return 0;
}
