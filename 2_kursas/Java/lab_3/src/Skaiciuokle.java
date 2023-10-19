import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Skaiciuokle extends JFrame {

    private JPanel mainpanle;
    private JTextField debtPrice;
    private JLabel DebtSum;
    private JTextField Month;
    private JTextField Year;
    private JLabel dateTerm;
    private JLabel textYear;
    private JLabel monthText;
    private JLabel Name;
    private JLabel graphType;
    private JComboBox GraphTypeSelect;
    private JButton Result;
    private JTextField precantage;
    private JLabel ProcetageText;
    private JButton Filter;
    private JTextField FillSttart;
    private JTextField FillEnd;
    private JButton delay;
    private JTextField dellayStart;
    private JTextField dellayFIn;

    Color btnDefault;

    public double numbers[] = new double[15];

    public Skaiciuokle(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainpanle);
        this.pack();
        this.setVisible(true);
        //Action listener for result button
        Result.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                numbers[0] = Double.parseDouble(debtPrice.getText());
                numbers[1] = Double.parseDouble(Month.getText());
                numbers[2] = Double.parseDouble(Year.getText());
                numbers[3] = Double.parseDouble(precantage.getText());
                if (String.valueOf(GraphTypeSelect.getSelectedItem()) == "Anuiteto grafikas") {
                    numbers[4] = 1;
                } else {
                    numbers[4] = 2;
                }
                new Atsakymai("Rezultatai", numbers);
            }
        });
       //Action listener for filter button
        Filter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                btnDefault = Result.getBackground();
                Filter.setBackground(btnDefault);
                numbers[5] = Double.parseDouble(FillSttart.getText());
                numbers[6] = Double.parseDouble(FillEnd.getText());
                numbers[7] = 1; //flag
                if (numbers[5] > numbers[6] || numbers[6] > (numbers[1]*12 + numbers[2]))
                {
                    numbers[7] = 0;
                    Filter.setBackground(Color.RED);

                }
                if (numbers[5] == 0 && numbers[6] == 0) {
                    Filter.setBackground(btnDefault);
                    numbers[7] = 0;
                }
            }
        });

        //Action listener for delay button
        delay.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                btnDefault = Result.getBackground();
                delay.setBackground(btnDefault);
                numbers[8] = Double.parseDouble(dellayStart.getText());
                numbers[9] = Double.parseDouble(dellayFIn.getText());
                numbers[10] = 1; //flag
                if (numbers[8] > numbers[9])
                     {
                    numbers[10] = 0;
                    delay.setBackground(Color.RED);

                }
                if (numbers[8] == 0 && numbers[9] == 0) {
                    delay.setBackground(btnDefault);
                    numbers[10] = 0;
                }
            }
        });
    }


}
