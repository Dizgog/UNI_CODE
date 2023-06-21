import java.io.*;
import java.net.*;

public class POP3ClientHandler implements Runnable {
    private Socket clientSocket;
    private BufferedReader reader;
    private PrintWriter writer;

    public POP3ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        try {
            // Create input and output streams for client communication
            reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            writer = new PrintWriter(clientSocket.getOutputStream(), true);

            // Send the server greeting
            sendResponse("+OK POP3 server ready");

            // Read client commands and handle them
            String clientCommand;
            while ((clientCommand = reader.readLine()) != null) {
                handleCommand(clientCommand);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            closeConnection();
        }
    }

    private void handleCommand(String command) {
        // Process client commands here
        // Example: Send a response based on the received command
        if (command.equalsIgnoreCase("QUIT")) {
            sendResponse("+OK Bye");
            closeConnection();
        } else {
            sendResponse("-ERR Unknown command");
        }
    }

    private void sendResponse(String response) {
        writer.println(response);
    }

    private void closeConnection() {
        try {
            if (reader != null)
                reader.close();
            if (writer != null)
                writer.close();
            if (clientSocket != null)
                clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
