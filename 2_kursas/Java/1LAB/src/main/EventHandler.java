package main;

public class EventHandler {

    Gamepanel gp;

    boolean canTouchEvent = true;

    EventHandler(Gamepanel gp){
        this.gp = gp;

    }
    public void checkEvent(){
        if(gp.player.hasBanana == 3 && gp.currentMap == 0) {
            teleport(1,1,1);
        }
        if(gp.player.hasBanana == 6 && gp.currentMap == 1) {
            teleport(2,1,1);
        }
//        if(gp.player.hasBanana == 9 && gp.currentMap == 2) {
//            teleport(2,1,1);
//        }
    }

    public boolean hit (int col, int row, int map){
        boolean hit = false;
        if(gp.player.worldX == col * gp.tileSize && gp.player.worldY == row * gp.tileSize && gp.currentMap == map){
           System.out.println("help me");
            hit = true;
        }
        return hit;
    }
    public void teleport(int map, int col, int row){
        gp.currentMap = map;
        gp.player.worldX = gp.tileSize * col;
        gp.player.worldY = gp.tileSize * row;

    }
}
