package Entity;

import main.Gamepanel;
import main.KeyHandler;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.awt.Graphics2D;

public class Player extends Entity {

    KeyHandler keyH;

    public final int screenX;
    public final int screenY;

    int hasKey = 0;
    public int hasBanana = 0;

    Font Comic_sans;

    public Player(Gamepanel gp, KeyHandler keyH) {

        super(gp);
        this.keyH = keyH;
        screenX = gp.screenWidth / 2 - (gp.tileSize / 2);
        screenY = gp.screenHeight / 2 - (gp.tileSize / 2);

        solidArea = new Rectangle(8, 16, 32, 32);
        solidAreaDefaultX = 8;
        solidAreaDefaultY = 16;

        Comic_sans = new Font("SansSerif", Font.PLAIN, 40);

        setDefaultValues();
        getPlayerImage();
    }

    public void setDefaultValues() {
        worldX = gp.tileSize * 1;
        worldY = gp.tileSize * 1;
        speed = 4;
        direction = "down";
    }

    public void getPlayerImage() {
        try {
            up1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_up_1.png"));
            up2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_up_2.png"));
            down1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_down_1.png"));
            down2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_down_2.png"));
            right1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_right_1.png"));
            right2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_right_2.png"));
            left1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_left_1.png"));
            left2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("player/dude_left_2.png"));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void update() {

        if (keyH.downPressed == true || keyH.leftPressed == true || keyH.upPressed == true || keyH.rightPressed == true) {
            if (keyH.upPressed == true) {
                direction = "up";
            }
            if (keyH.downPressed == true) {
                direction = "down";
            }
            if (keyH.leftPressed == true) {
                direction = "left";
            }
            if (keyH.rightPressed == true) {
                direction = "right";
            }
            //check tile colision
            collisionOn = false;
            gp.cChecker.checkTile(this);
            int objIndex = gp.cChecker.checkObject(this, true);
            pickUpObject(objIndex);

            //Check monster collision
            int monsterIndex = gp.cChecker.checkEntity(this, gp.monster);
            interactMonster(monsterIndex);

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


    }

    public void pickUpObject(int index) {
        if (index != 999) {

            String objectName = gp.obj[gp.currentMap][index].name;

            switch (objectName) {
                case "Key":
                    hasKey++;
                    gp.obj[gp.currentMap][index] = null;
                    break;
                case "Banana":
                    hasBanana++;
                    gp.obj[gp.currentMap][index] = null;
            }
        }
    }

    public void interactMonster(int index) {

        if (index != 999) {
            setDefaultValues();
        }
    }

    public void draw(Graphics2D g2) {

        g2.setFont(Comic_sans);
        g2.setColor(Color.white);
        BufferedImage image = null;

        switch (direction) {
            case "up":
                if (spriteNumber == 1) {
                    image = up1;
                }
                if (spriteNumber == 2) {
                    image = up2;
                }
                break;
            case "down":
                if (spriteNumber == 1) {
                    image = down1;
                }
                if (spriteNumber == 2) {
                    image = down2;
                }
                break;
            case "left":
                if (spriteNumber == 1) {
                    image = left1;
                }
                if (spriteNumber == 2) {
                    image = left2;
                }
                break;
            case "right":
                if (spriteNumber == 1) {
                    image = right1;
                }
                if (spriteNumber == 2) {
                    image = right2;
                }
                break;
        }
        g2.drawImage(image, screenX, screenY, gp.tileSize, gp.tileSize, null);
        g2.drawString("X: " +worldX/ gp.tileSize, 85, 25*16);
        g2.drawString("Y: " + worldY/ gp.tileSize, 85, 30*16);

    }
}
