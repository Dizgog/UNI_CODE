package main;

import java.awt.*;
import java.awt.image.BufferedImage;

import Object.*;
import Entity.Player;

public class UI {
    Gamepanel gp;
    Player en;

    Font Comic_sans;

    BufferedImage bananaImage;

    public UI(Gamepanel gp) {
        this.gp = gp;

        Comic_sans = new Font("SansSerif", Font.PLAIN, 40);
        OBJ_Banana banana = new OBJ_Banana();
        bananaImage = banana.Image;
    }

    public void draw(Graphics2D g2) {

        g2.setFont(Comic_sans);
        g2.setColor(Color.white);
        g2.drawImage(bananaImage, gp.tileSize / 2, gp.tileSize / 2, gp.tileSize, gp.tileSize, null);
        g2.drawString("x " + gp.player.hasBanana, 85, 57);

    }
}
