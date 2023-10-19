package button_hell;

import javax.swing.*;
import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.Comparator;
import java.util.List;
import java.util.Vector;
import java.util.stream.Collectors;

import static button_hell.studList.filter;

public class listGUI extends JFrame {

    private JTable table;

    private JScrollPane scroll;
    private JPanel Result;

    public listGUI(String title, String[] filter) {
        super(title);


        String[] tempCol = (String[]) Groups.collsForList(filter);
        String[][] tempData = (String[][]) Groups.dataForList(filter);
        String[][] data = new String[tempData.length + 1][tempCol.length + 1];
        for (int i = 0; i < tempCol.length; i++) {
            System.out.println(tempCol[i]);
        }
        table = new JTable(tempData, tempCol);
        table.setBounds(30, 40, 200, 300);
        JScrollPane scroll = new JScrollPane(table);
        this.add(scroll);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        //this.setContentPane(Result);
        this.pack();
        this.setSize(700, 600);
        this.setVisible(true);


    }
}
