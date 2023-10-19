// The server should support the following commands:
// USER <username>
// PASS <password>
// STAT
// LIST
// RETR <message number>
// DELE <message number>
// RSET
// NOOP
// QUIT
// The server should respond to each command with the appropriate response code. The server should
// The server should support the following response codes:
// +OK
// -ERR

import java.io.*;
import java.net.*;

public class Server {
    ServerSocket serverSocket;
    private ClientHandler[] clients = new ClientHandler[10];

    public Server(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        System.out.println("Server started. Listening on port " + port);

        while (!serverSocket.isClosed()) {
            Socket socket = serverSocket.accept();
            System.out.println("Client accepted");
            ClientHandler clientHandler = new ClientHandler(socket);
            Thread thread = new Thread(clientHandler);
            thread.start();
        }
    }

    public static void main(String[] args) throws IOException {
        new Server(110);
    }
}