package button_hell;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.SwingUtilities;

import button_hell.Groups;
import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.PageSize;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.GrayColor;
import com.itextpdf.text.pdf.PdfPCell;
import com.itextpdf.text.pdf.PdfPTable;
import com.itextpdf.text.pdf.PdfWriter;

import static button_hell.studList.filter;

public class JTableToPdf {

    private JFrame frame;
    private JTable table;
    private JButton button;
    private Document document;
    private PdfWriter writer;
    private JScrollPane scrollPane;


    public JTableToPdf(String title) {
        createAndShowGui(title);

    }

    public void openPdf(String title) throws FileNotFoundException, DocumentException {
        document = new Document(PageSize.A4, 30, 30, 30, 30);
        writer = PdfWriter.getInstance(document, new FileOutputStream(title + "pdf"));
        document.open();
    }

    public void closePdf() {
        document.close();
    }

    public void addData(PdfPTable pdfTable) throws DocumentException {
        pdfTable.setHeaderRows(1);

        PdfPCell cell = new PdfPCell(new Paragraph(table.getColumnName(0)));
        cell.setBackgroundColor(new GrayColor(0.7f));
        pdfTable.addCell(cell);

        cell = new PdfPCell(new Paragraph(table.getColumnName(1)));
        cell.setBackgroundColor(new GrayColor(0.7f));
        pdfTable.addCell(cell);

        for (int a = 2; a < table.getColumnCount(); a++) {
            cell = new PdfPCell(new Paragraph(table.getColumnName(a)));
            cell.setBackgroundColor(new GrayColor(0.7f));
            pdfTable.addCell(cell);
        }


        for (int i = 0; i < table.getRowCount() - 1; i++) {
            for (int j = 0; j < table.getColumnCount(); j++) {
                pdfTable.addCell(table.getModel().getValueAt(i, j).toString());
            }
        }

        document.add(pdfTable);
    }

    public void createAndShowGui(String title) {
        frame = new JFrame("PDF creator");
        String data[][] = (String[][]) Groups.dataForList(filter);
        String temp[] = (String[]) Groups.collsForList(filter);
        table = new JTable(data, temp);
        table.setBorder(BorderFactory.createLineBorder(Color.RED));
        button = new JButton("Create PDF");

        scrollPane = new JScrollPane(table);
        try {
            PdfPTable pdfTable = new PdfPTable(table.getColumnCount());
            openPdf(title);
            addData(pdfTable);
            closePdf();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (DocumentException e1) {
            e1.printStackTrace();
        }
    }
}