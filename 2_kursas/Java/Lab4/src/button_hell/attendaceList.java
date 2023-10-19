package button_hell;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class attendaceList extends JFrame {
    private JPanel mainPanel;
    private JComboBox groupNames;
    private JComboBox studName;
    private JTextField year;
    private JComboBox month;
    private JComboBox day;
    private JButton button1;

    public attendaceList(String title) {

        super(title);
        for (String key : Groups.groupStud.keySet()) {
            groupNames.addItem(key);
            for (int t = 0; t < Groups.groupStud.get(key).size(); t++) {
                studName.addItem(Groups.groupStud.get(key).get(t));
            }
        }
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
        this.setVisible(true);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Groups.addAttendance((String) studName.getSelectedItem(), year.getText(), (String) month.getSelectedItem(), (String) day.getSelectedItem());
            }
        });
    }
}
