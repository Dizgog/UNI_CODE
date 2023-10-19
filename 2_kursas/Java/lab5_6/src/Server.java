import com.opencsv.CSVWriter;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server implements Runnable {

    private ArrayList<ConnectionHandler> connections;
    private ServerSocket server;
    private boolean done;
    private ExecutorService pool;
    private Vector<String> nameList = new Vector<>();

    private List<String[]> data = new ArrayList<String[]>();
    private static final SimpleDateFormat sdf1 = new SimpleDateFormat("HH:mm:ss");
    private static final SimpleDateFormat sdf2 = new SimpleDateFormat("DD_HH");

    public Server() {
        connections = new ArrayList<>();
        done = false;
    }

    @Override
    public void run() {
        try {
            server = new ServerSocket(9999);
            pool = Executors.newCachedThreadPool();
            while (!done) {
                Socket client = server.accept();
                ConnectionHandler handler = new ConnectionHandler(client);
                connections.add(handler);
                pool.execute(handler);
            }

        } catch (Exception e) {
            shutdown();
        }
    }

    public void broadCast(String message) {
        Timestamp timestamp = new Timestamp(System.currentTimeMillis());
        for (ConnectionHandler ch : connections) {
            if (ch != null) {
                ch.sendMessage(sdf1.format(timestamp) + " " + message);
            }
        }
        data.add(new String[]{"[General]", sdf1.format(timestamp), message});
        writeToCsv();

    }

    public void privateMesg(String message, String sender, String reciver) {
        for (ConnectionHandler ch : connections) {

            if (Objects.equals(ch.nickname, reciver)) {
                Timestamp timestamp = new Timestamp(System.currentTimeMillis());
                ch.sendMessage(sdf1.format(timestamp) + " " + "Message from " + sender + ": " + message);
                data.add(new String[]{"[Private]", sdf1.format(timestamp), "Message from " + sender + "to" + reciver + ": " + message});
                writeToCsv();
            }
        }


    }

    public void shutdown() {
        try {
            done = true;
            if (!server.isClosed()) {
                server.close();
            }
            for (ConnectionHandler ch : connections) {
                ch.shutdown();
            }
        } catch (IOException e) {
            //Ig
        }

    }

    private void writeToCsv() {
        Timestamp timestamp = new Timestamp(System.currentTimeMillis());
        String filePath = "LOG_" + sdf2.format(timestamp) + ".csv";
        File file = new File(filePath);
        try {
            // create FileWriter object with file as parameter
            FileWriter outputfile = new FileWriter(file);

            // create CSVWriter with '|' as separator
            CSVWriter writer = new CSVWriter(outputfile, '|',
                    CSVWriter.NO_QUOTE_CHARACTER,
                    CSVWriter.DEFAULT_ESCAPE_CHARACTER,
                    CSVWriter.DEFAULT_LINE_END);

            writer.writeAll(data);

            // closing writer connection
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class ConnectionHandler implements Runnable {
        private Socket client;
        private BufferedReader in;
        private PrintWriter out;
        private String nickname;

        public ConnectionHandler(Socket client) {
            this.client = client;
        }

        @Override
        public void run() {
            try {

                out = new PrintWriter(client.getOutputStream(), true);
                in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                out.println("Please enter nickname: ");
                nickname = in.readLine();
                nameList.add(nickname);
                System.out.println(nickname + " Connected");
                broadCast(nickname + " has joined");
                String message;
                while ((message = in.readLine()) != null) {
                    if (message.startsWith("/nick")) {
                        String[] messageSplit = message.split(" ", 2);
                        if (messageSplit.length == 2) {
                            broadCast(nickname + " renamed themselves to " + messageSplit[1]);
                            System.out.println(nickname + " renamed themselves to " + messageSplit[1]);
                            nickname = messageSplit[1];
                            out.println("Succesfully changed nickname to " + nickname);
                        } else {
                            out.println("No nickname provided!");
                        }
                    } else if (message.startsWith("/quit")) {
                        broadCast(nickname + " left the chat!");
                        System.out.println(nickname + " left the chat!");
                        shutdown();
                    } else if (message.startsWith("/msg")) {
                        String[] messageSplit = message.split(" ", 3);
                        if (messageSplit.length == 3) {
                            if (nameList.contains(messageSplit[1])) {
                                privateMesg(messageSplit[2], nickname, messageSplit[1]);
                                out.println("Message to " + messageSplit[1] + ": " + messageSplit[2]);
                            } else {
                                out.println("No one with that name");
                            }
                        } else {
                            out.println("No message");
                        }
                    } else {
                        broadCast(nickname + ": " + message);
                    }
                }
            } catch (IOException e) {
                shutdown();
            }
        }

        public void sendMessage(String messsage) {
            out.println(messsage);
        }

        public void shutdown() {
            try {
                in.close();
                out.close();
                nameList.remove(nickname);
                if (!client.isConnected()) {
                    client.close();
                }
            } catch (IOException e) {
                //ig
            }
        }


    }

    public static void main(String[] args) {
        Server server = new Server();
        server.run();

    }
}
