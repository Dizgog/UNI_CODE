package Object;

import tiles.Tiles;

import javax.imageio.ImageIO;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class OBJ_Key extends SuperObject {

    public OBJ_Key() {

        name = "Key";
        try {
            System.out.println("key");
            File file = new File("res/Object/key.png");
            FileInputStream fis = new FileInputStream(file);
            Image = ImageIO.read(fis);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
