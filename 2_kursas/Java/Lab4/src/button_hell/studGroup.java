package button_hell;

import javax.swing.*;
import javax.xml.crypto.Data;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class studGroup extends JFrame {
    private JPanel groupPanel;
    private JTextField textField1;
    private JButton išsaugotiButton;

    public studGroup(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(groupPanel);
        this.pack();
        this.setVisible(true);
        išsaugotiButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Groups.addGroup(textField1.getText());
            }
        });
    }

}