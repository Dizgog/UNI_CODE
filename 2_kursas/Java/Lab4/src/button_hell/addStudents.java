package button_hell;

//import org.apache.poi.ss.usermodel.Workbook;

import com.aspose.cells.License;
import com.aspose.cells.Range;
import com.aspose.cells.Workbook;
import com.aspose.cells.Worksheet;
import com.aspose.cells.*;
import org.apache.poi.ss.usermodel.Cell;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.Iterator;
import java.util.Scanner;

import static java.lang.String.valueOf;

public class addStudents extends JFrame {
    private JPanel mainpanel;
    private JComboBox groupNames;
    private JTextField studenName;
    private JButton button1;
    private JTextField csvFileName;
    private JButton button2;
    private JTextField excelFileName;
    private JButton button3;

    public addStudents(String title) {

        super(title);

        for (String key : Groups.groupStud.keySet()) {
            groupNames.addItem(key);
        }


        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(mainpanel);
        this.pack();
        this.setVisible(true);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Groups.addStudents(studenName.getText(), (String) groupNames.getSelectedItem());

            }
        });

        //CSV FAILO ADD
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                {
                    String line = "";
                    String splitBy = ",";
                    try {
                        //parsing a CSV file into BufferedReader class constructor
                        BufferedReader br = new BufferedReader(new FileReader(csvFileName.getText() + ".csv"));
                        while ((line = br.readLine()) != null)   //returns a Boolean value
                        {
                            String[] employee = line.split(splitBy);    // use comma as separator
                            if (!Groups.groupStud.containsKey(employee[0])) {
                                Groups.addGroup(employee[0]);
                            }
                            if (!Groups.attendance.containsKey(employee[1].substring(1))) {
                                Groups.addStudents((employee[1]).substring(1), employee[0]);
                            }
                            for (int a = 2; a < employee.length; a++) {
                                Groups.attendance.get(employee[1].substring(1)).add(employee[a].substring(1));
                            }
                        }
                    } catch (FileNotFoundException ex) {
                        throw new RuntimeException(ex);
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                }
            }
        });

        //EXCEL TYPE ADD
        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {

                    // Load the Excel file into Workbook to be converted to array
                    Workbook excelWorkbookToArray = new Workbook(excelFileName.getText() + ".xlsx");

                    // Get the reference to the first sheet of the workbook for conversion to array
                    Worksheet worksheet = excelWorkbookToArray.getWorksheets().get(0);
                    Cells cells = excelWorkbookToArray.getWorksheets().get(0).getCells();
                    Range range = worksheet.getCells().getMaxDisplayRange();

                    int tcols = range.getColumnCount();

                    int trows = range.getRowCount();
                    Object[][] arr = cells.exportArray(0, 0, trows, tcols);
                    for (int i = 0; i < trows; i++) {
                        if (!Groups.groupStud.containsKey(valueOf(arr[i][0]))) {
                            Groups.addGroup((String) arr[i][0]);
                        }
                        Groups.addStudents((valueOf(arr[i][1])), valueOf(arr[i][0]));
                        for (int j = 2; j < tcols; j++) {
                            Groups.attendance.get(valueOf(arr[i][1])).add((valueOf(arr[i][j])).substring(0, (valueOf(arr[i][j])).length() - 9));
                        }
                    }

                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
            }
        });
    }
}



