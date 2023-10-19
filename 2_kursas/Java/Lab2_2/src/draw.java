import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Iterator;


public class draw extends JFrame {
    ArrayList<Line2D.Float> Lines = new ArrayList<Line2D.Float>();
    Point2D.Float pt1;
    Point2D.Float pt2;
    public draw(String title) throws HeadlessException {

        super(title);
        setBounds(30, 30, 900, 650);
        Container ControlHost = getContentPane();
        ControlHost.setLayout(new FlowLayout());


        //Sample 03: Handle Mouse Events
        addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                pt1 = new Point2D.Float(e.getX(), e.getY());
            }
            @Override
            public void mouseReleased(MouseEvent e) {
                pt2 = new Point2D.Float(e.getX(), e.getY());
                Line2D.Float line2D = new Line2D.Float(pt1, pt2);
                Lines.add(line2D);
                repaint();
            }
        });
    }

    @Override
    public void paint(Graphics g)
    {
        //Sample 04: Convert the Graphics Object to Graphics2D
        Graphics2D g2d = (Graphics2D) g;

        //Sample 05: Iterate Line Array and Draw
        Iterator<Line2D.Float> itr = Lines.iterator();
        while(itr.hasNext())
        {
            g2d.draw(itr.next());
        }
    }
}
