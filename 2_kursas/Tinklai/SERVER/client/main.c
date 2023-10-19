#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1" // Change this to the server's IP address
#define SERVER_PORT 8888      // Change this to the server's port number
#define MAX_MSG_SIZE 2000     // Maximum size of the message buffer

int main() {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char server_reply[MAX_MSG_SIZE], answer[MAX_MSG_SIZE];
    int recv_size;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    // Create a socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d" , WSAGetLastError());
        return 1;
    }

    // Prepare the sockaddr_in structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect error");
        return 1;
    }


    if ((recv_size = recv(s, server_reply, MAX_MSG_SIZE, 0)) == SOCKET_ERROR) {
        printf("Recv failed with error code : %d", WSAGetLastError());
        return 1;
    }
    server_reply[recv_size] = '\0';
    printf("%s", server_reply);

    // Read the user's answer from standard input
    fgets(answer, MAX_MSG_SIZE, stdin);

    // Send the answer to the server
    if (send(s, answer, strlen(answer), 0) < 0) {
        printf("Send failed with error code : %d", WSAGetLastError());
        return 1;
    }

    // Receive the response from the server
    if ((recv_size = recv(s, server_reply, MAX_MSG_SIZE, 0)) == SOCKET_ERROR) {
        printf("Recv failed with error code : %d", WSAGetLastError());
        return 1;
    }
    server_reply[recv_size] = '\0';
    printf("%s", server_reply);

    closesocket(s);
    WSACleanup();

    return 0;
}
