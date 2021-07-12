#include"graphic.h"
#include "CONTAINER.h"
void CONTAINER::load() {
    CreateData();
    LoadGraphics();
}
void CONTAINER::CreateData() {
    Data.title.backColor = COLOR(200, 200, 60);

    Data.fade.color = COLOR(255, 136, 0);
    Data.fade.speed = 255;

    Data.map.fileName = "assets\\map1.txt";
    Data.map.chipSize = 50;
}
void CONTAINER::LoadGraphics() {
    Data.stage.backImg = loadImage("assets\\back.png"); 
    Data.map.blockImg = loadImage("assets\\block.png");
}
