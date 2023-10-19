import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import button_hell.*;

public class mainWindow extends JFrame {
    private JButton studGroups;
    private JButton addSrtudets;
    private JButton atendenceList;
    private JButton studentList;
    private JButton editStudentInfo;
    private JPanel mainPanel;
    private JButton saveInFile;

    public Vector<String> groupNam = new Vector<String>();

    public mainWindow(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
        this.setVisible(true);


        studGroups.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new studGroup("Studentų grupės įvedimas");
            }
        });
        addSrtudets.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new addStudents("Studentų į grupes įtraukimas");
            }
        });
        editStudentInfo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new editData("Redaguoti sarašą");
            }
        });
        atendenceList.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new attendaceList("Lankomumo sarašas");
            }
        });
        studentList.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new studList("Filtras");
            }
        });
        saveInFile.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new saveInFile("Išsaugoti");
            }
        });
    }
}