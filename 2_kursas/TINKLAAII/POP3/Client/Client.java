// Mail client
// 1. Create a Socket object
// 2. Create a BufferedReader object
// 3. Create a PrintWriter object
// 4. Send a request to the server
// 5. Read the response from the server
// 6. Close the client connection

import java.io.*;
import java.net.*;
import java.util.*;

public class Client {
    static final String[] POP3Commands = new String[] { "USER", "PASS", "LIST", "STAT", "RETR", "DELE", "RSET", "QUIT", "HELP"};

    private class Request {
        public String command;
        public String[] args;

        public Request(String command, String[] args) {
            this.command = command;
            this.args = args;
        }
    }

    private Socket socket;
    private BufferedReader receiver;
    private PrintWriter requester;

    public Client(String host, int port) throws IOException {
        this.socket = new Socket("pine.spike.lt" , 110  );
        receiver = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        requester = new PrintWriter(socket.getOutputStream(), true);

        Scanner input = new Scanner(System.in);
        boolean isReady = false;
        while (!isReady) {
            System.out.print("Enter your username: ");
            SendRequest(User(input.nextLine()));
            if (ReadResponse().startsWith("-ERR"))
                continue;

            System.out.print("Enter your password: ");
            SendRequest(Pass(input.nextLine()));
            if (ReadResponse().startsWith("-ERR"))
                continue;

            isReady = true;

            System.out.print("Succesfully connected\n");
            System.out.print("Type in \"HELP\" for help\n");
        }

        while (socket.isConnected()) {
            String request = input.nextLine();
            Request parsedRequest = identifyRequest(request);
            // Check if command is defined in POP3
            if (!isPOP3Command(parsedRequest.command)) {
                System.out.println("Command not found");
                continue;
            }
            if (parsedRequest.command.equals("HELP")) {
                Help();
                continue;
            }
            SendRequest(request);
            handleMessage(ReadResponse(), parsedRequest.command);
            if(parsedRequest.command.equals("QUIT")){
                closeConnection();
                break;
            }
        }
        input.close();
        closeConnection();
    }

    public static void main(String[] args) throws IOException {
        new Client("localhost", 110);
    }

    public void SendRequest(String request) {
        this.requester.println(request);
    }

    public String ReadResponse() throws IOException {
        String response = "";
        String line = this.receiver.readLine();
        response += line + "\r\n";

        // If it's ready: Response is multiline
        if (this.receiver.ready()) {
            while ((line = this.receiver.readLine()) != null) {
                if (line.equals(".")) {
                    break;
                }
                response += line + "\r\n";
            }
        }
        //Clear any leftover data
        while(this.receiver.ready()){
            this.receiver.readLine();
        }
        return response;
    }

    public Request identifyRequest(String request) {
        String[] requestParts = request.split(" ");
        String command = requestParts[0];
        String[] arguments = Arrays.copyOfRange(requestParts, 1, requestParts.length);
        return new Request(command, arguments);
    }

    public boolean isPOP3Command(String command) {
        for (String POP3Command : POP3Commands) {
            if (POP3Command.equals(command)) {
                return true;
            }
        }
        return false;
    }

    public void handleMessage(String response, String command) {
        String[] lines = response.split("\r\n");
        String responseCode = lines[0].split(" ")[0];

        String responseMessage = lines[0].substring(responseCode.length() + 1);
        if (responseCode.equals("-ERR")) {
            System.out.println(responseMessage);
            return;
        }

        switch (command.toUpperCase()) {
            case "STAT":
                System.out.println("Total messages: " + responseMessage.split(" ")[0]);
                System.out.println("Size: " + responseMessage.split(" ")[1]);
                break;
            case "LIST":
                if (lines.length == 1) {
                    System.out.println("Message ID: " + responseMessage.split(" ")[0]);
                    System.out.println("Size: " + responseMessage.split(" ")[1]);
                } else {
                    System.out.println(responseMessage);
                    System.out.println("ID | Size");
                    for (int i = 1; i < lines.length; i++) {
                        System.out.println(lines[i].replace(" ", " | "));
                    }
                }
                break;
            case "RETR":
                System.out.println("Size: " + responseMessage);
                for (int i = 1; i < lines.length; i++) {
                    System.out.println(lines[i]);
                }
                break;
            case "DELE":
                System.out.println(responseMessage);
            case "RSET":
                System.out.println(responseMessage);
                break;
            case "QUIT":
                System.out.println(responseMessage);
                break;
            case "HELP":
                Help();
            default:
                System.out.println(responseMessage);
                break;
        }

    }

    // Help command
    public void Help() {
        // Print all commands with brief description
        System.out.println("COMMAND | DESCRIPTION");
        for (String POP3Command : POP3Commands) {
            switch (POP3Command) {
                case "USER":
                    System.out.println("USER <username> | Specify username");
                    break;
                case "PASS":
                    System.out.println("PASS <password> | Specify password");
                    break;
                case "LIST":
                    System.out.println("LIST | List all messages");
                    break;
                case "STAT":
                    System.out.println("STAT | Get mailbox info");
                    break;
                case "RETR":
                    System.out.println("RETR <messageNumber> | Retrieve a message");
                    break;
                case "DELE":
                    System.out.println("DELE <messageNumber> | Mark a message as deleted");
                    break;
                case "RSET":
                    System.out.println("RSET | Reset the session");
                    break;
                case "QUIT":
                    System.out.println("QUIT | Terminate connection");
                    break;
                default:
                    break;
            }
        }
    }

    // Terminate connection
    public String Quit() {
        return "QUIT";
    }

    // Authentication
    public String User(String username) {
        return "USER " + username;
    }

    // Authentication
    public String Pass(String password) {
        return "PASS " + password;
    }

    // Basic mailbox info: number of messages and total size
    public String Stat() {
        return "STAT";
    }

    // All messages in mailbox with size
    public String List() {
        return "LIST";
    }

    // Retrieve a full content of a specific message
    public String Retr(int messageNumber) {
        return "RETR " + messageNumber;
    }

    // Mark a message as deleted
    public String Dele(int messageNumber) {
        return "DELE " + messageNumber;
    }

    // Reset the session
    public String Rset() {
        return "RSET";
    }

    // Help request
    public void closeConnection() {
        try {
            if (this.receiver != null) {
                this.receiver.close();
            }
            if (this.requester != null) {
                this.requester.close();
            }
            if (this.socket != null) {
                this.socket.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}