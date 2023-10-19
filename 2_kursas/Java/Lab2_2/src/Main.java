import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;

public class Main extends JFrame {


    public static void main(String args[]) throws HeadlessException {
            draw frame = new draw("Line2D & Point2D Example");
            frame.setVisible(true);

//        JPanel p = new JPanel() {
//            int line = 0;
//            Point pointStart = null;
//            Point pointEnd   = null;
//
//
//
//            {
//                addMouseListener(new MouseAdapter() {
//                    public void mousePressed(MouseEvent e) {
//                        pointStart = e.getPoint();
//                    }
//
//                    public void mouseReleased(MouseEvent e) {
//                        pointStart = null;
//                    }
//                });
//                addMouseMotionListener(new MouseMotionAdapter() {
//                    public void mouseMoved(MouseEvent e) {
//                        pointEnd = e.getPoint();
//                    }
//
//                    public void mouseDragged(MouseEvent e) {
//                        pointEnd = e.getPoint();
//                        repaint();
//                    }
//                });
//            }
//            public void paint(Graphics g) {
//                super.paint(g);
//                if (pointStart != null) {
//
//                    g.setColor(Color.RED);
//                    g.drawLine(pointStart.x, pointStart.y, pointEnd.x, pointEnd.y);
//                    line++;
//                }
//            }
//        };
//        f.add(p);
//        f.setVisible(true);
        }
}