import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client extends JFrame implements Runnable {

    private Socket client;
    private BufferedReader in;
    private PrintWriter out;
    private boolean done;

    // JFrame frame = new chatGui();
    private JTextField textField1;
    private JTextArea textArea1;
    private JPanel panel;

    private JScrollPane scroll;

    @Override
    public void run() {
        JFrame frame = new JFrame("Chat room");
        this.setSize(1000, 1000);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(panel);
        this.pack();
        this.setVisible(true);
        try {

            Socket client = new Socket("127.0.0.1", 9999);
            out = new PrintWriter(client.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(client.getInputStream()));

            textField1.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    //   textArea1.append(textField1.getText() + "\r\n");
                    if (textField1.getText().equals("/quit")) {
                        shutdown();
                    } else {
                        out.println(textField1.getText() + "");
                        textField1.setText("");
                    }


                }
            });

            String inMessage;
            while ((inMessage = in.readLine()) != null) {
                System.out.println(inMessage);
                textArea1.append(inMessage + "\r\n");
            }
        } catch (IOException e) {
            shutdown();

        }
    }

    public void shutdown() {
        done = true;
        try {
            in.close();
            out.close();
            if (!client.isClosed()) {
                client.close();
            }
        } catch (IOException e) {
            //Ig
        }
    }


    public static void main(String[] args) {

        Client client = new Client();
        client.run();
    }
}
