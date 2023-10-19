package button_hell;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class editData extends JFrame {
    private JPanel mainPanel;
    private JComboBox groupListEdit;
    private JTextField studNameEdit;
    private JButton išsaugotiDuomenysButton;
    private JComboBox grouplistSet;
    private JComboBox studNameSet;

    public editData(String title) {
        super(title);

        for (String key : Groups.groupStud.keySet()) {
            grouplistSet.addItem(key);
            groupListEdit.addItem(key);
            for (int t = 0; t < Groups.groupStud.get(key).size(); t++) {
                studNameSet.addItem(Groups.groupStud.get(key).get(t));
            }
        }

        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
        this.setVisible(true);

        išsaugotiDuomenysButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Groups.addStudents(studNameEdit.getText(), (String) groupListEdit.getSelectedItem());
                ArrayList temp = (Groups.attendance.get(studNameSet.getSelectedItem()));
                Groups.attendance.remove(studNameSet.getSelectedItem());
                Groups.attendance.put(studNameEdit.getText(), temp);
                Groups.groupStud.get(grouplistSet.getSelectedItem()).remove(studNameSet.getSelectedItem());
            }
        });
    }
}