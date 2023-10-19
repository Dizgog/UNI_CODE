package Entity;

import main.Gamepanel;

import javax.imageio.ImageIO;
import java.io.IOException;
import java.util.Random;

public class NPC_MONKE extends Entity{

    public NPC_MONKE(Gamepanel gp){
        super(gp);

        direction = "right";
        speed = 3;

        getImage();
    }
    public void getImage() {
        try {
            up1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_up_1.png"));
            up2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_up_2.png"));
            down1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_down_1.png"));
            down2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_down_2.png"));
            right1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_right_1.png"));
            right2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_right_2.png"));
            left1 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_left_1.png"));
            left2 = ImageIO.read(getClass().getClassLoader().getResourceAsStream("monsters/monke_left_2.png"));

        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setAction() {

        actionLockCounter++;
        if(actionLockCounter == 120){

        Random random = new Random();
        int i = random.nextInt(4)+1;
        speed = i;
        actionLockCounter = 0;
        }
    }
}
