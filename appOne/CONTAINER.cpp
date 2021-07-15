#include"graphic.h"
#include "CONTAINER.h"
#include"ANIM.h"
CONTAINER::~CONTAINER() {
    delete Data.explosionChara.anims[0];
    delete[] Data.explosionChara.anims;
    delete Data.batBulletChara.anims[0];
    delete[] Data.batBulletChara.anims;
    delete Data.batChara.anims[0];
    delete[] Data.batChara.anims;
    delete Data.pumpkinChara.anims[1];
    delete Data.pumpkinChara.anims[0];
    delete[] Data.pumpkinChara.anims;
    delete Data.playerBulletChara.anims[0];
    delete[] Data.playerBulletChara.anims;
    delete Data.playerChara.anims[1];
    delete Data.playerChara.anims[0];
    delete[] Data.playerChara.anims;
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

    Data.playerChara.charaId = 'a';

    Data.playerBulletChara.charaId = 'b';
    Data.playerBulletChara.groupId = 0;//味方グループは0 
    Data.playerBulletChara.initHp = 1;
    Data.playerBulletChara.speed = 4.7f*60;
    Data.playerBulletChara.offsetLeft = 20.0f;
    Data.playerBulletChara.offsetTop = 20.0f;
    Data.playerBulletChara.offsetRight = 30.0f;
    Data.playerBulletChara.offsetBottom = 30.0f;
    
    Data.pumpkinChara.charaId = 'c';

    Data.batChara.charaId = 'd';
    Data.batChara.initHp = 10;
    Data.batChara.groupId = 1;
    Data.batChara.offsetLeft = 10.0f;
    Data.batChara.offsetTop = 10.0f;
    Data.batChara.offsetRight = 30.0f;
    Data.batChara.offsetBottom = 35.0f;

    Data.bat.elapsedTime = 0;
    Data.bat.interval = 0.016f;
    Data.bat.triggerCnt = 60;
    Data.bat.triggerInterval = 240;
    Data.bat.trigger1st = 220;
    Data.bat.trigger2nd = 225;
    Data.bat.trigger3rd = 230;
    Data.bat.trigger4th = 235;
    Data.bat.bulletCharaId = 'e';
    Data.bat.damageTime = 0;
    Data.bat.damageInterval = 5*0.016f;
    Data.bat.appearBulletOffsetX = 20.0f;
    Data.bat.alphaLowVal = 25;

    Data.batBulletChara.charaId = 'e';
    Data.batBulletChara.groupId = 1;//敵グループは1
    Data.batBulletChara.initHp = 1;
    Data.batBulletChara.speed = 4.7f*60;
    Data.batBulletChara.offsetLeft = 20.0f;
    Data.batBulletChara.offsetTop = 20.0f;
    Data.batBulletChara.offsetRight = 30.0f;
    Data.batBulletChara.offsetBottom = 30.0f;

    Data.explosionChara.charaId = 'f';

    Data.charaMng.numPlayers = 1;
    Data.charaMng.numPlayerBullets = 5;
    Data.charaMng.numPumpkins = 5;
    Data.charaMng.numBats = 5;
    Data.charaMng.numBatBullets = 12;
    Data.charaMng.numExplosions = 2;
}
void CONTAINER::LoadGraphics() {
    Data.stage.backImg = loadImage("assets\\back.png"); 
    
    Data.map.blockImg = loadImage("assets\\block.png");
    
    Data.playerChara.anims = new ANIM * [2];
    Data.playerChara.anims[0] = new ANIM;
    Data.playerChara.anims[0]->load(2, "assets\\playerR");
    Data.playerChara.anims[0]->setInterval(0.1f);
    Data.playerChara.anims[1] = new ANIM;
    Data.playerChara.anims[1]->load(2, "assets\\playerL");
    Data.playerChara.anims[1]->setInterval(0.1f);

    Data.playerBulletChara.anims = new ANIM * [1];
    Data.playerBulletChara.anims[0] = new ANIM;
    Data.playerBulletChara.anims[0]->load(1, "assets\\playerBullet");
    Data.playerBulletChara.anims[0]->setInterval(0.1f);

    Data.pumpkinChara.anims = new ANIM * [2];
    Data.pumpkinChara.anims[0] = new ANIM;
    Data.pumpkinChara.anims[0]->load(4, "assets\\pumpkinL");
    Data.pumpkinChara.anims[0]->setInterval(0.1f);
    Data.pumpkinChara.anims[1] = new ANIM;
    Data.pumpkinChara.anims[1]->load(4, "assets\\pumpkinR");
    Data.pumpkinChara.anims[1]->setInterval(0.1f);

    Data.batChara.anims = new ANIM*[1];
    Data.batChara.anims[0] = new ANIM;
    Data.batChara.anims[0]->load(4, "assets\\bat");
    Data.batChara.anims[0]->setInterval(0.1f);

    Data.batBulletChara.anims = new ANIM * [1];
    Data.batBulletChara.anims[0] = new ANIM;
    Data.batBulletChara.anims[0]->load(1, "assets\\batBullet");
    Data.batBulletChara.anims[0]->setInterval(0.1f);

    Data.explosionChara.anims = new ANIM * [1];
    Data.explosionChara.anims[0] = new ANIM;
    Data.explosionChara.anims[0]->load(48, "assets\\explosion\\a");
    Data.explosionChara.anims[0]->setInterval(0.016f);
    Data.explosionChara.anims[0]->setStartIdx(24);
    //Data.explosionChara.anims[0]->noLoop();
    Data.explosionChara.imgIdx = 24;
}
