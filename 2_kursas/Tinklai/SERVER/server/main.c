#include <stdio.h>
#include <winsock2.h>

int main() {
    WSADATA wsa;
    SOCKET s, new_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char client_reply[2000], answer[2000];

    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        printf("WSAStartup failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Winsock initialized.\n");

    //Create a socket
    if((s = socket(AF_INET, SOCK_STREAM, 0 )) == INVALID_SOCKET) {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    
    if(bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d", WSAGetLastError());
        return 1;
    }

    printf("Bind done.\n");

    //Listen to incoming connections
    listen(s, 3);
    
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    while(1){
    c = sizeof(struct sockaddr_in);
    new_socket = accept(s, (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET) {
        printf("Accept failed with error code : %d", WSAGetLastError());
        return 1;
    }

    puts("Connection accepted");

    // Send question to client
    send(new_socket, "What is the capital of France?\n", strlen("What is the capital of France?\n"), 0);

    // Receive client's answer
    recv_size = recv(new_socket, client_reply, 2000, 0);
    client_reply[recv_size] = '\0';

    // Check client's answer and respond accordingly
    if (strcmp(client_reply, "Paris\n") == 0) {
        strcpy(answer, "Correct!\n");
    } else {
        strcpy(answer, "Incorrect.\n");
    }

    // Send response to client
    send(new_socket, answer, strlen(answer), 0);
    }
    closesocket(s);
    WSACleanup();

    return 0;
}
