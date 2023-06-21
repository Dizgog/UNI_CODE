import java.io.*;
import java.net.*;

public class POP3Client {
    public static void main(String[] args) {
        try {
            // Connect to the POP3 server
            Socket socket = new Socket("127.0.0.1", 110);
            
            // Create input and output streams for server communication
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            
            // Read the server greeting
            String serverResponse = reader.readLine();
            System.out.println("Server: " + serverResponse);
            
            // Send USER command
            writer.println("USER your_username");
            serverResponse = reader.readLine();
            System.out.println("Server: " + serverResponse);
            
            // Send PASS command
            writer.println("PASS your_password");
            serverResponse = reader.readLine();
            System.out.println("Server: " + serverResponse);
            
            // Send other commands as needed
            // For example, to list messages:
            writer.println("LIST");
            serverResponse = reader.readLine();
            System.out.println("Server: " + serverResponse);
            
            // Close the connection
            writer.println("QUIT");
            serverResponse = reader.readLine();
            System.out.println("Server: " + serverResponse);
            
            // Close the streams and socket
            reader.close();
            writer.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
