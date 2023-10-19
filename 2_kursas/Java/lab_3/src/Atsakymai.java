import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.util.Vector;
import java.io.*;

public class Atsakymai extends JFrame {
    private JPanel Results;

    private JTable table;

    private JScrollPane scroll;

    private JButton file;
    private JButton Graph;

    private double debtSum, duration, precantage, fillstart, fillend, fillflag, dellaystart, dellayend, dellayflag;
    public Vector<Double> amountV = new Vector();
    public Vector monthV = new Vector();
    public Vector<Double> leftToPayV = new Vector();
    private Vector<Double> interestV = new Vector();
    private Vector<Double> precantageV = new Vector();
    private Vector<Double> creditV = new Vector<>();

    DecimalFormat dec = new DecimalFormat("#0.00");

    String data[][];
    String column[] = {"Mėnuo", "liko mokėti", "mokėstis", "Palukanos", "Kreditas"};

    public Atsakymai(String title, double temp[]) {
        super(title);

        //Rewrite data from Skaiciuokle class to this
        debtSum = temp[0];
        duration = temp[2] + temp[1] * 12;
        precantage = (temp[3] / 12) / 100; //33346,25
        fillstart = temp[5];
        fillend = temp[6];
        fillflag = temp[7];
        dellaystart = temp[8];
        dellayend = temp[9];
        dellayflag = temp[10];

        //Preparing array for table
        data = new String[(int)(duration + ((int)(dellayend-dellaystart)))][5];

        //Flag for annuity or linear method
        if (temp[4] == 1) {
            annuity();
        } else {
            linear();
        }

        //Adding everything to jframe
        table = new JTable(data, column);
        table.setBounds(30, 40, 200, 300);
        scroll = new JScrollPane(table);
        this.add(scroll);
        this.add(file, BorderLayout.AFTER_LAST_LINE);
        this.add(Graph, BorderLayout.PAGE_END);
        this.setSize(700, 600);
        this.setVisible(true);

        //Writing to file :0
        file.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                writeToFile();
            }
        });

        Graph.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
               new Graph("Grafas", data);
            }
        });
    }

    private void annuity() {
        Double num;

        //Without dellay
        if(dellayflag == 0) {
            num = debtSum * (((precantage * Math.pow(1 + precantage, duration))) / (Math.pow(1 + precantage, duration) - 1));
            for (int i = 0; i < duration; i++) {
                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                amountV.add(num); //amount
                interestV.add(debtSum * precantage); //interest
                creditV.add(num - interestV.get(i)); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay
            }
            addToList();
        }
        else{
            duration = duration;
            num = debtSum * (((precantage * Math.pow(1 + precantage, duration))) / (Math.pow(1 + precantage, duration) - 1));
            //If with delay
            for (int i = 0; i < (int)dellaystart - 1; i++) {

                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                amountV.add(num); //amount
                interestV.add(debtSum * precantage); //interest
                creditV.add(num - interestV.get(i)); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay


            }
            for (int i = (int)dellaystart - 1; i < (int)dellayend - 1; i++) {

                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                amountV.add(num); //amount
                interestV.add(debtSum * precantage); //interest
                creditV.add(0.0); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay


            }
            for (int i = (int)dellayend - 1; i < duration + (dellayend-dellaystart); i++) {

                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                amountV.add(num); //amount
                interestV.add(debtSum * precantage); //interest
                creditV.add(num - interestV.get(i)); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay


            }
            addToList();
        }
    }

    private void linear() {
        //Without dellay
        if(dellayflag == 0) {
            double credit = debtSum / duration;
            for (int i = 0; i < duration; ++i) {
                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                interestV.add(debtSum * precantage); //interest
                amountV.add(credit + interestV.get(i)); //amount
                creditV.add(credit); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay

            }
            addToList();
        }
        else{
            duration = duration + ((int)(dellayend-dellaystart)*2);
            double credit = debtSum / duration;
            //With delay
            for (int i = 0; i < dellaystart - 1; ++i) {
                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                interestV.add(debtSum * precantage); //interest
                amountV.add(credit + interestV.get(i)); //amount
                creditV.add(credit); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay

            }
            for (int i = (int)dellaystart - 1; i < (int)dellayend - 1; i++) {
                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                interestV.add(debtSum * precantage); //interest
                amountV.add(credit + interestV.get(i)); //amount
                creditV.add(0.0); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay
            }


            for (int i = (int)dellayend - 1; i < duration + (dellayend-dellaystart); i++) {
                monthV.add(i + 1); //month
                leftToPayV.add(debtSum); //left to pay
                interestV.add(debtSum * precantage); //interest
                amountV.add(credit + interestV.get(i)); //amount
                creditV.add(credit); //creddit
                debtSum = debtSum - creditV.get(i); //recounting how much to pay

            }
            addToList();
        }
    }


    private void addToList() {
        //Flag without filter
        if (fillflag == 1) {
            for (int row = (int) fillstart-1; row < (int) fillend; row++) {
                data[row-(int)fillstart+1][0] = row + 1 + "";
                data[row-(int)fillstart+1][1] = dec.format(leftToPayV.get(row));
                data[row-(int)fillstart+1][2] = dec.format(amountV.get(row));
                data[row-(int)fillstart+1][3] = dec.format(interestV.get(row));
                data[row-(int)fillstart+1][4] = dec.format(creditV.get(row));
            }
        } else {
            //flag with filter
            int temp = 3;
            for (int row = 0; row < duration + (dellayend-dellaystart); row++) {
                System.out.println(temp++);
                data[row][0] = row + 1 + "";
                data[row][1] = dec.format(leftToPayV.get(row));
                data[row][2] = dec.format(amountV.get(row));
                data[row][3] = dec.format(interestV.get(row));
                data[row][4] = dec.format(creditV.get(row));
            }
        }
    }

    //Writing to file :0
    private void writeToFile(){

        try {
            // Creates a FileWriter
            FileWriter file = new FileWriter("output.txt");

            // Creates a BufferedWriter
            BufferedWriter output = new BufferedWriter(file);

            // Writes the string to the file

            for(int y = 0; y < 5; y++) {
                output.write(column[y]);
                output.write("     \t");
            }
            output.newLine();
            for(int y = 0; y < data.length; y++) {
                for (int i = 0; i < 5; i++) {
                    output.write(data[y][i]);
                    output.write("        \t");
                }
                output.newLine();
            }
            // Closes the writer
            output.close();
        }
        catch (Exception e) {
            e.getStackTrace();
        }
    }
}

