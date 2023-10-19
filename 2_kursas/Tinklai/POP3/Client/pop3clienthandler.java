
import java.io.*;
import java.net.*;

public class pop3clienthandler implements Runnable {
    private Socket clientSocket;
    private BufferedReader reader;
    private PrintWriter writer;

    public pop3clienthandler(Socket clientSocket) {
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
        String response;
        if (command.equalsIgnoreCase("USER username")) {
            response = "+OK User recognized";
        } else if (command.equalsIgnoreCase("PASS password")) {
            response = "+OK Authentication successful";
        } else if (command.equalsIgnoreCase("STAT")) {
            response = "+OK 2 1024"; // Sample response: 2 messages, total size 1024 bytes
        } else if (command.equalsIgnoreCase("LIST")) {
            response = "+OK\r\n1 512\r\n2 512\r\n."; // Sample response: Message 1 has size 512, Message 2 has size 512
        } else if (command.equalsIgnoreCase("RETR 1")) {
            response = "+OK 512\r\nThis is the content of message 1.";
        } else if (command.equalsIgnoreCase("RETR 2")) {
            response = "+OK 512\r\nThis is the content of message 2.";
        } else if (command.equalsIgnoreCase("DELE 1")) {
            response = "+OK Message 1 marked for deletion";
        } else if (command.equalsIgnoreCase("DELE 2")) {
            response = "+OK Message 2 marked for deletion";
        } else if (command.equalsIgnoreCase("NOOP")) {
            response = "+OK";
        } else if (command.equalsIgnoreCase("RSET")) {
            response = "+OK Messages unmarked for deletion";
        } else if (command.equalsIgnoreCase("QUIT")) {
            response = "+OK Bye";
            closeConnection();
        } else {
            response = "-ERR Unknown command";
        }

        sendResponse(response);
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
