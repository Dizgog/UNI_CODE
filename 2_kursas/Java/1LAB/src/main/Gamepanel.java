package main;

import Entity.Entity;
import Entity.Player;
import tiles.TilesManager;
import Object.SuperObject;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Gamepanel extends JPanel implements Runnable {
    //Screen settings
    final int originalTileSize = 16; // 16*16 tile
    final int scale = 3;
    public final int tileSize = originalTileSize * scale;
    public final int maxScreenCol = 16;
    public final int maxScreenRow = 12;
    public final int screenWidth = tileSize * maxScreenCol;
    public final int screenHeight = tileSize * maxScreenRow;

    //WORLD SETTINGS
    public final int maxWorldCol = 50;
    public final int maxWorldRow = 50;
    public final int maxMap = 10;
    public int currentMap = 0;
    public final int worldWidth = tileSize * maxWorldCol;
    public final int worldHeight = tileSize * maxWorldRow;

    //FPS
    int FPS = 60;

    TilesManager tileM = new TilesManager(this);
    KeyHandler keyH = new KeyHandler();
    Thread gameThread;
    public CollisionChecker cChecker = new CollisionChecker(this);
    public AssetSetter aSetter = new AssetSetter(this);
    public EventHandler eventH = new EventHandler(this);
    public UI ui = new UI(this);
    public Player player = new Player(this, keyH);
    public SuperObject obj[][] = new SuperObject[maxMap][10];
    public Entity monster[][] = new Entity[maxMap][10];

    //set players default position
    int playerX = 100;
    int playerY = 100;
    int playerSpeed = 4;

    public Gamepanel() {
        this.setPreferredSize(new Dimension(screenWidth, screenHeight));
        this.setBackground(Color.black);
        this.setDoubleBuffered(true);
        this.addKeyListener(keyH);
        this.setFocusable(true);
        this.requestFocus();
    }

    public void setUpGame() {
        aSetter.setObject();
        aSetter.setMonster();
    }

    public void StartGameThread() {
        gameThread = new Thread(this);
        gameThread.start();
    }

    @Override
    public void run() {

        double drawInterval = 1000000000 / FPS;
        double delta = 0;
        long LastTime = System.nanoTime();
        long currentTime;
        long timer = 0;
        int drawCount = 0;
        while (gameThread != null) {

            currentTime = System.nanoTime();
            delta += (currentTime - LastTime) / drawInterval;
            timer += (currentTime - LastTime);
            LastTime = currentTime;

            if (delta >= 1) {
                update();
                repaint();
                delta--;
                drawCount++;
            }

            if (timer >= 1000000000) {
                //System.out.println("FPS:" + drawCount);
                drawCount = 0;
                timer = 0;
            }

        }
    }

    public void update() {
        player.update();
        eventH.checkEvent();
        for (int i = 0; i < monster[1].length; i++) {
            if (monster[currentMap][i] != null) {
                monster[currentMap][i].update();
            }
        }
    }

    public void paintComponent(Graphics g) {

        super.paintComponent(g);

        Graphics2D g2 = (Graphics2D) g;

        tileM.draw(g2);

        for (int i = 0; i < obj[1].length; i++) {
            if (obj[currentMap][i] != null) {
                obj[currentMap][i].draw(g2, this);
            }
        }

        for (int i = 0; i < monster[1].length; i++) {
            if (monster[currentMap][i] != null) {
                monster[currentMap][i].draw(g2);
            }
        }

        player.draw(g2);

        ui.draw(g2);

        g2.dispose();
    }
}
