import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class POP3Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(110);
            System.out.println("POP3 server started on port 110");

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected: " + clientSocket.getInetAddress().getHostAddress());

                // Create a new thread to handle the client
                Thread clientThread = new Thread(new POP3ClientHandler(clientSocket));
                clientThread.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
