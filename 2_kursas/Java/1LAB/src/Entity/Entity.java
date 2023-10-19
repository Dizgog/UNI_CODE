package Entity;

import main.Gamepanel;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Entity {
    Gamepanel gp;
    public int worldX, worldY;
    public int speed;

    public BufferedImage up1, up2, down1, down2, left1, left2, right1, right2;
    public String direction;

    public int spriteCounter = 0;
    public int spriteNumber = 1;

    public Rectangle solidArea = new Rectangle(0, 0, 46, 46);

    public int solidAreaDefaultX;
    public int solidAreaDefaultY;

    public int actionLockCounter = 0;
    public boolean collisionOn = false;

    public Entity(Gamepanel gp) {
        this.gp = gp;
    }

    public void setAction() {
    }

    public void update() {
        setAction();

        collisionOn = false;
        gp.cChecker.checkTile(this);

        //If collision is false player can move
        if (collisionOn == false) {

            switch (direction) {
                case "up":
                    worldY -= speed;
                    break;
                case "down":
                    worldY += speed;
                    break;
                case "left":
                    worldX -= speed;
                    break;
                case "right":
                    worldX += speed;
                    break;
            }
        } else {

            switch (direction) {
                case "up":
                    direction = "down";
                    break;
                case "down":
                    direction = "up";
                    break;
                case "left":
                    direction = "right";
                    break;
                case "right":
                    direction = "left";
                    break;
            }
        }
        spriteCounter++;
        if (spriteCounter > 12) {
            if (spriteNumber == 1) {
                spriteNumber = 2;
            } else if (spriteNumber == 2) {
                spriteNumber = 1;
            }
            spriteCounter = 0;
        }
    }

    public void draw(Graphics2D g2) {

        BufferedImage Image = null;

        int screenX = worldX - gp.player.worldX + gp.player.screenX;
        int screenY = worldY - gp.player.worldY + gp.player.screenY;


        switch (direction) {
            case "up":
                if (spriteNumber == 1) {
                    Image = up1;
                }
                if (spriteNumber == 2) {
                    Image = up2;
                }
                break;
            case "down":
                if (spriteNumber == 1) {
                    Image = down1;
                }
                if (spriteNumber == 2) {
                    Image = down2;
                }
                break;
            case "left":
                if (spriteNumber == 1) {
                    Image = left1;
                }
                if (spriteNumber == 2) {
                    Image = left2;
                }
                break;
            case "right":
                if (spriteNumber == 1) {
                    Image = right1;
                }
                if (spriteNumber == 2) {
                    Image = right2;
                }
                break;
        }
        g2.drawImage(Image, screenX, screenY, gp.tileSize, gp.tileSize, null);
    }
}
