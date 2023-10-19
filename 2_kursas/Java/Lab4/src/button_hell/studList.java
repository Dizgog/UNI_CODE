package button_hell;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Comparator;
import java.util.List;
import java.util.Vector;
import java.util.stream.Collectors;

public class studList extends JFrame {
    private JPanel mainPanel;
    private JButton filtrasButton;
    private JButton rodytiSarašąButton;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    public static String[] filter = new String[3];

    public studList(String title) {
        super(title);

        Vector<String> Dates = new Vector<>();
        for (String key : Groups.attendance.keySet()) {
            for (int t = 0; t < Groups.attendance.get(key).size(); t++) {
                Dates.add(Groups.attendance.get(key).get(t));
            }
        }

        List<String> UniqueDates = Dates.stream().distinct().collect(Collectors.toList());
        UniqueDates.sort(Comparator.naturalOrder());

        for (String key : UniqueDates) {
            comboBox1.addItem(key);
            comboBox2.addItem(key);
        }

        filtrasButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                filter[0] = (String) comboBox1.getSelectedItem();
                filter[1] = (String) comboBox2.getSelectedItem();
                filter[2] = "True";
            }
        });
        rodytiSarašąButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new listGUI("Sarašas", filter);
            }
        });

        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
        this.setVisible(true);
    }
}
