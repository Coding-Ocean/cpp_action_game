#include"graphic.h"
#include "CONTAINER.h"
#include"ANIM.h"
CONTAINER::~CONTAINER() {
    delete Data.explosion.anims[0];
    delete[] Data.explosion.anims;
    delete Data.batBullet.anims[0];
    delete[] Data.batBullet.anims;
    delete Data.bat.anims[0];
    delete[] Data.bat.anims;
    delete Data.pumpkin.anims[1];
    delete Data.pumpkin.anims[0];
    delete[] Data.pumpkin.anims;
    delete Data.playerBullet.anims[0];
    delete[] Data.playerBullet.anims;
    delete Data.player.anims[1];
    delete Data.player.anims[0];
    delete[] Data.player.anims;
}
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

    Data.player.charaId = 'a';
    Data.playerBullet.charaId = 'b';
    Data.pumpkin.charaId = 'c';
    Data.bat.charaId = 'd';
    Data.batBullet.charaId = 'e';
    Data.explosion.charaId = 'f';

    Data.charaMng.numPlayers = 1;
    Data.charaMng.numPlayerBullets = 5;
    Data.charaMng.numPumpkins = 5;
    Data.charaMng.numBats = 5;
    Data.charaMng.numBatBullets = 10;
    Data.charaMng.numExplosions = 2;
}
void CONTAINER::LoadGraphics() {
    Data.stage.backImg = loadImage("assets\\back.png"); 
    
    Data.map.blockImg = loadImage("assets\\block.png");
    
    Data.player.anims = new ANIM * [2];
    Data.player.anims[0] = new ANIM;
    Data.player.anims[0]->load(2, "assets\\playerR");
    Data.player.anims[0]->setInterval(0.1f);
    Data.player.anims[1] = new ANIM;
    Data.player.anims[1]->load(2, "assets\\playerL");
    Data.player.anims[1]->setInterval(0.1f);

    Data.playerBullet.anims = new ANIM * [1];
    Data.playerBullet.anims[0] = new ANIM;
    Data.playerBullet.anims[0]->load(1, "assets\\playerBullet");
    Data.playerBullet.anims[0]->setInterval(0.1f);

    Data.pumpkin.anims = new ANIM * [2];
    Data.pumpkin.anims[0] = new ANIM;
    Data.pumpkin.anims[0]->load(4, "assets\\pumpkinL");
    Data.pumpkin.anims[0]->setInterval(0.1f);
    Data.pumpkin.anims[1] = new ANIM;
    Data.pumpkin.anims[1]->load(4, "assets\\pumpkinR");
    Data.pumpkin.anims[1]->setInterval(0.1f);

    Data.bat.anims = new ANIM*[1];
    Data.bat.anims[0] = new ANIM;
    Data.bat.anims[0]->load(4, "assets\\bat");
    Data.bat.anims[0]->setInterval(0.1f);

    Data.batBullet.anims = new ANIM * [1];
    Data.batBullet.anims[0] = new ANIM;
    Data.batBullet.anims[0]->load(1, "assets\\batBullet");
    Data.batBullet.anims[0]->setInterval(0.1f);

    Data.explosion.anims = new ANIM * [1];
    Data.explosion.anims[0] = new ANIM;
    Data.explosion.anims[0]->load(48, "assets\\explosion\\a");
    Data.explosion.anims[0]->setInterval(0.016f);
    Data.explosion.anims[0]->setStartIdx(24);
    //Data.explosion.anims[0]->noLoop();
    Data.explosion.imgIdx = 24;
}
