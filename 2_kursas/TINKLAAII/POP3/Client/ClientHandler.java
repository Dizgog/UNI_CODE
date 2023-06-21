import java.io.*;
import java.net.Socket;

public class ClientHandler implements Runnable {

    private static class Mail {
        private String sender;
        private String text;
        private String date;
        private String title;
        public boolean deleted = false;

        public Mail(String sender, String title, String text, String date ) {
            this.sender = sender;
            this.title = title;
            this.text = text;
            this.date = date;
        }

        public String getFormattedEmail() {
            return "From: " + sender + "\r\n" + "Title: " + title + "\r\n" + "Date: " + date + "\r\n" + "Text: " + text;
        }
    }

    private BufferedReader receiver;
    private PrintWriter responder;
    public Socket socket;

    private static final String username = "Peter";
    private static final String password = "Spiderman";
    private Mail[] emails = {
            new Mail("Alice", "Important Announcement", "Please be informed that the meeting has been rescheduled to tomorrow.", "2022-05-12"),
            new Mail("Bob", "Project Update", "Great news! We've successfully completed the first phase of the project ahead of schedule.", "2022-05-13"),
            new Mail("Charlie", "Conference Invitation", "You're invited to speak at the upcoming conference on the topic of AI and its impact on society.", "2022-05-14"),
            new Mail("David", "Training Workshop Registration", "Don't miss out on our upcoming training workshop. Register now to secure your spot!", "2022-05-15"),
            new Mail("Eve", "Job Opportunity", "We have an exciting job opening in our company. Please review the attached job description.", "2022-05-16"),
            // Add more emails here
    };

    public ClientHandler(Socket socket) {
        try {
            this.socket = socket;
            this.receiver = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            this.responder = new PrintWriter(socket.getOutputStream(), true);
        } catch (IOException e) {
            closeConnection();
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (socket.isConnected()) {
            try {
                String request = receiver.readLine();
                System.out.println("Request: " + request);
                sendResponse(handleRequest(request));
                if (request.equals("QUIT")) {
                    closeConnection();
                    break;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void sendResponse(String response) throws IOException {
        System.out.println("Response: " + response);
        responder.println(response);
    }

    public String handleRequest(String request) {
        String[] requestParts = request.split(" ");
        String command = requestParts[0];
        String[] arguments = new String[requestParts.length - 1];
        System.arraycopy(requestParts, 1, arguments, 0, arguments.length);

        switch (command) {
            case "USER":
                return User(arguments);
            case "PASS":
                return Pass(arguments);
            case "LIST":
                return List(arguments);
            case "STAT":
                return Stat(arguments);
            case "RETR":
                return Retr(arguments);
            case "DELE":
                return Dele(arguments);
            case "RSET":
                return Rset(arguments);
            case "QUIT":
                return Quit(arguments);
            default:
                return Err() + "Command not found";
        }
    }

    public String User(String[] args) {
        if (args.length != 1) {
            return Err() + "Invalid number of arguments";
        }
        if (args[0].equals(username)) {
            return Ok() + "User accepted";
        } else {
            return Err() + "User not found";
        }
    }

    public String Pass(String[] args) {
        if (args.length != 1) {
            return Err() + "Invalid number of arguments";
        }
        if (args[0].equals(password)) {
            return Ok() + "Password accepted";
        } else {
            return Err() + "Password not accepted";
        }
    }

    public String List(String[] args) {
        if (args.length > 1) {
            return Err() + "Invalid number of arguments";
        }
        if (args.length == 0) {
            StringBuilder response = new StringBuilder(Ok() + emails.length + " messages\r\n");
            for (int i = 0; i < emails.length; i++) {
                if (!emails[i].deleted) {
                    response.append(i + 1).append(" ").append(emails[i].getFormattedEmail().length()).append("\r\n");
                }
            }
            return response.append(".\r\n").toString();
        } else {
            int index = Integer.parseInt(args[0]);
            if (index > 0 && index <= emails.length) {
                return Ok() + (index) + " " + emails[index - 1].getFormattedEmail().length();
            } else {
                return Err() + "Message not found";
            }
        }
    }

    public String Stat(String[] args) {
        if (args.length != 0) {
            return Err() + "Invalid number of arguments";
        }
        int totalSize = 0;
        for (Mail email : emails) {
            totalSize += email.getFormattedEmail().length();
        }
        return Ok() + emails.length + " " + totalSize;
    }

    public String Retr(String[] args) {
        if (args.length != 1) {
            return Err() + "Invalid number of arguments";
        }
        int index = Integer.parseInt(args[0]);
        if (index > 0 && index <= emails.length) {
            return Ok() + emails[index - 1].getFormattedEmail().length() + " octets \r\n" +
                    emails[index - 1].getFormattedEmail() + "\r\n.\r\n";
        } else {
            return Err() + "Message not found";
        }
    }

    public String Dele(String[] args) {
        if (args.length != 1) {
            return Err() + "Invalid number of arguments";
        }
        int index = Integer.parseInt(args[0]);
        if (index > 0 && index <= emails.length) {
            emails[index - 1].deleted = true;
            return Ok() + "Message " + index + " deleted";
        } else {
            return Err() + "Message not found";
        }
    }

    public String Rset(String[] args) {
        if (args.length != 0) {
            return Err() + "Invalid number of arguments";
        }
        for (Mail email : emails) {
            email.deleted = false;
        }
        return Ok() + "OK";
    }

    public String Quit(String[] args) {
        if (args.length != 0) {
            return Err() + "Invalid number of arguments";
        }
        return Ok() + "Quitting, goodbye";
    }

    public String Ok() {
        return "+OK ";
    }

    public String Err() {
        return "-ERR ";
    }

    public void closeConnection() {
        try {
            if (this.receiver != null) {
                this.receiver.close();
            }
            if (this.responder != null) {
                this.responder.close();
            }
            if (this.socket != null) {
                this.socket.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
