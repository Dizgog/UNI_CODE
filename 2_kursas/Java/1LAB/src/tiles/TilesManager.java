package tiles;

import main.Gamepanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.io.*;

public class TilesManager {
    Gamepanel gp;
    public Tiles[] tiles;

    public int[][][] mapTileNum;

    public TilesManager(Gamepanel gp) {
        this.gp = gp;

        tiles = new Tiles[10];
        mapTileNum = new int[gp.maxMap][gp.maxWorldCol][gp.maxWorldRow];
        getTileImage();
        loadMap("res/maps/world1.json", 0);
        loadMap("res/maps/world2.json", 1);
        loadMap("res/maps/world3.json", 2);
    }

    public void getTileImage() {
        System.out.println("Image loading started");

        //setup(0, "grass.png", false);
        setup(0, "grass2.png", false);
        setup(1, "wall.png", true);
        setup(2, "water.png", true);
        //setup(3, "earth.png", false);
        setup(3, "earth1.png", false);
        //setup(4, "tree.png", true);
        setup(4,"tree1.png", true);
        setup(5, "sand.png", false);


        System.out.println("Image loading finished");
    }

    public void setup(int index, String name, boolean coll) {
        try {
            File file = new File("res/tiles/" + name);
            FileInputStream fis = new FileInputStream(file);
            tiles[index] = new Tiles();
            tiles[index].image = ImageIO.read(fis);
            tiles[index].collision = coll;

        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void loadMap(String NamePass, int map) {

        try {
            FileReader fr = new FileReader(NamePass);
            BufferedReader br = new BufferedReader(fr);

            int col = 0;
            int row = 0;

            while (col < gp.maxWorldCol && row < gp.maxWorldRow) {
                String line = br.readLine();
                while (col < gp.maxWorldCol) {
                    String numbers[] = line.split(" ");

                    int num = Integer.parseInt(numbers[col]);
                    mapTileNum[map][col][row] = num;
                    col++;
                }
                if (col == gp.maxWorldCol) {
                    col = 0;
                    row++;
                }
            }
            br.close();
        } catch (FileNotFoundException e) {
            System.out.println("The file does not exist.");
        } catch (IOException e) {
            System.out.println("The file cannot be read.");
        } catch (NumberFormatException e) {
            System.out.println("The file contains non numeric data.");
        } catch (Exception e) {
            System.out.println(e);
        }

    }

    public void draw(Graphics2D g2) {

        int worldCol = 0;
        int worldRow = 0;

        while (worldCol < gp.maxWorldCol && worldRow < gp.maxWorldRow) {

            int tileNum = mapTileNum[gp.currentMap][worldCol][worldRow];

            int worldX = worldCol * gp.tileSize;
            int worldY = worldRow * gp.tileSize;
            int screenX = worldX - gp.player.worldX + gp.player.screenX;
            int screenY = worldY - gp.player.worldY + gp.player.screenY;


            g2.drawImage(tiles[tileNum].image, screenX, screenY, gp.tileSize, gp.tileSize, null);
//
//            if(worldX + gp.tileSize > (gp.player.worldX - gp.player.screenX) &&
//               worldX - gp.tileSize > (gp.player.worldX + gp.player.screenX) &&
//               worldY + gp.tileSize > (gp.player.worldY - gp.player.screenY) &&
//               worldY - gp.tileSize > (gp.player.worldY + gp.player.screenY)){
//
//                g2.drawImage(tiles[tileNum].image, screenX, screenY, gp.tileSize, gp.tileSize, null);
//            }


            worldCol++;
            if (worldCol == gp.maxWorldCol) {
                worldCol = 0;
                worldRow++;
            }
        }
    }
}
