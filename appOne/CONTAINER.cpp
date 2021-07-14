#include"graphic.h"
#include "CONTAINER.h"
#include"ANIM.h"
CONTAINER::~CONTAINER() {
    delete Data.explosion.anims[0];
    delete[] Data.explosion.anims;
    delete Data.batBullet.anims[0];
    delete[] Data.batBullet.anims;
    delete Data.batChara.anims[0];
    delete[] Data.batChara.anims;
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
    Data.playerBullet.groupId = 0;//味方グループは0 
    Data.playerBullet.initHp = 1;
    Data.playerBullet.speed = 4.7f*60;
    Data.playerBullet.offsetLeft = 20.0f;
    Data.playerBullet.offsetTop = 20.0f;
    Data.playerBullet.offsetRight = 30.0f;
    Data.playerBullet.offsetBottom = 30.0f;
    
    Data.pumpkin.charaId = 'c';

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

    Data.batBullet.charaId = 'e';
    Data.batBullet.groupId = 1;//敵グループは1
    Data.batBullet.initHp = 1;
    Data.batBullet.speed = 4.7f*60;
    Data.batBullet.offsetLeft = 20.0f;
    Data.batBullet.offsetTop = 20.0f;
    Data.batBullet.offsetRight = 30.0f;
    Data.batBullet.offsetBottom = 30.0f;

    Data.explosion.charaId = 'f';

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

    Data.batChara.anims = new ANIM*[1];
    Data.batChara.anims[0] = new ANIM;
    Data.batChara.anims[0]->load(4, "assets\\bat");
    Data.batChara.anims[0]->setInterval(0.1f);

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
