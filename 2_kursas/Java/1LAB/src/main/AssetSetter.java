package main;

import Entity.NPC_MONKE;
import Object.OBJ_Key;
import Object.*;

public class AssetSetter {

    Gamepanel gp;

    AssetSetter(Gamepanel gp) {
        this.gp = gp;
    }

    public void setObject() {

        int mapNum = 0;

        gp.obj[mapNum][0] = new OBJ_Banana();
        gp.obj[mapNum][0].worldX = 16 * gp.tileSize; //16
        gp.obj[mapNum][0].worldY = 4 * gp.tileSize; //4

        gp.obj[mapNum][1] = new OBJ_Banana();
        gp.obj[mapNum][1].worldX = 27 * gp.tileSize;
        gp.obj[mapNum][1].worldY = 8 * gp.tileSize;

        gp.obj[mapNum][2] = new OBJ_Banana();
        gp.obj[mapNum][2].worldX = 48 * gp.tileSize;
        gp.obj[mapNum][2].worldY = 11 * gp.tileSize;

        mapNum = 1;

        gp.obj[mapNum][0] = new OBJ_Banana();
        gp.obj[mapNum][0].worldX = 11 * gp.tileSize; //16
        gp.obj[mapNum][0].worldY = 5 * gp.tileSize; //4

        gp.obj[mapNum][1] = new OBJ_Banana();
        gp.obj[mapNum][1].worldX = 18 * gp.tileSize;
        gp.obj[mapNum][1].worldY = 17 * gp.tileSize;

        gp.obj[mapNum][2] = new OBJ_Banana();
        gp.obj[mapNum][2].worldX = 23 * gp.tileSize;
        gp.obj[mapNum][2].worldY = 17 * gp.tileSize;

    }

    public void setMonster() {

        int mapNum = 0;

        gp.monster[mapNum][0] = new NPC_MONKE(gp);
        gp.monster[mapNum][0].worldX = 8 * gp.tileSize;
        gp.monster[mapNum][0].worldY = 2 * gp.tileSize;
        gp.monster[mapNum][0].direction = "down";

        gp.monster[mapNum][1] = new NPC_MONKE(gp);
        gp.monster[mapNum][1].worldX = 4 * gp.tileSize;
        gp.monster[mapNum][1].worldY = 14 * gp.tileSize;
        gp.monster[mapNum][1].direction = "right";

        gp.monster[mapNum][2] = new NPC_MONKE(gp);
        gp.monster[mapNum][2].worldX = 25 * gp.tileSize;
        gp.monster[mapNum][2].worldY = 15 * gp.tileSize;
        gp.monster[mapNum][2].direction = "down";

        mapNum = 1;

        gp.monster[mapNum][0] = new NPC_MONKE(gp);
        gp.monster[mapNum][0].worldX = 2 * gp.tileSize;
        gp.monster[mapNum][0].worldY = 10 * gp.tileSize;
        gp.monster[mapNum][0].direction = "right";

        gp.monster[mapNum][1] = new NPC_MONKE(gp);
        gp.monster[mapNum][1].worldX = 13 * gp.tileSize;
        gp.monster[mapNum][1].worldY = 13 * gp.tileSize;
        gp.monster[mapNum][1].direction = "right";

        gp.monster[mapNum][2] = new NPC_MONKE(gp);
        gp.monster[mapNum][2].worldX = 18 * gp.tileSize;
        gp.monster[mapNum][2].worldY = 23 * gp.tileSize;
        gp.monster[mapNum][2].direction = "down";
    }
}
