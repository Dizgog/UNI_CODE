package Object;

import javax.imageio.ImageIO;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class OBJ_Banana extends SuperObject {
    public OBJ_Banana() {

        name = "Banana";
        try {

            File file = new File("res/Object/Banana.png");
            FileInputStream fis = new FileInputStream(file);
            Image = ImageIO.read(fis);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
