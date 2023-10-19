//Normantas Kuolas

package main;

import javax.swing.JFrame;

public class Main {
    public static void main(String[] args) {
        JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setTitle("Game");
        window.setResizable(true);

        Gamepanel gamepanel = new Gamepanel();
        window.add(gamepanel);

        gamepanel.setUpGame();

        gamepanel.StartGameThread();
        window.pack();

        window.setLocationRelativeTo(null);
        window.setVisible(true);

    }
}