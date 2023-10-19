package button_hell;

import com.opencsv.CSVWriter;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;

import static button_hell.studList.filter;

public class saveInFile extends JFrame {
    private JPanel mainPanel;
    private JButton saveCsv;
    private JButton saveExcel;
    private JTextField csvFile;
    private JTextField excelName;
    private JTextField pdfName;
    private JButton savePdf;

    public saveInFile(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
        this.setVisible(true);
        saveCsv.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                // create FileWriter object with file as parameter
                FileWriter outputfile = null;
                File file = new File(csvFile.getText() + ".csv");
                System.out.println(file);
                try {
                    outputfile = new FileWriter(file);
                    CSVWriter writer = new CSVWriter(outputfile);
                    writer.writeNext((String[]) Groups.collsForList(filter));
                    String temp[][] = (String[][]) Groups.dataForList(filter);
                    for (String key : Groups.groupStud.keySet()) {
                        for (int t = 0; t < Groups.groupStud.get(key).size(); t++) {
                            writer.writeNext(temp[t]);
                        }
                    }
                    writer.close();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }

                // create CSVWriter object filewriter object as parameter

            }
        });
        saveExcel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    XSSFWorkbook workbook = new XSSFWorkbook();
                    XSSFSheet sheet = workbook.createSheet("Students");

                    String[][] data = Groups.forOutput();
                    //Object[][] data = (Object[][]) Groups.dataForList(filter);
                    int rowCount = 0;

                    for (Object[] aData : data) {
                        Row row = sheet.createRow(++rowCount);
                        int columnCount = 0;

                        for (Object field : aData) {
                            Cell cell = row.createCell(++columnCount);
                            if (field instanceof String) {
                                cell.setCellValue((String) field);
                            } else if (field instanceof Integer) {
                                cell.setCellValue((Integer) field);
                            }
                        }

                    }
                    try (FileOutputStream outputStream = new FileOutputStream(excelName.getText() + ".xlsx")) {
                        workbook.write(outputStream);
                    }
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
            }
        });
        savePdf.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new JTableToPdf(pdfName.getText());
            }
        });
    }
}
