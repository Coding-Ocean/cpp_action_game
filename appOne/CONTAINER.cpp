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

    Data.stage.backColor = COLOR(255, 255, 255, 255);
    Data.stage.gameOverColor = COLOR(255, 0, 0);
    Data.stage.stageClearColor = COLOR(255, 255, 0);
    Data.stage.logoPx = (width - 800) / 2;
    Data.stage.logoPy = 220;
    Data.stage.backToTitleTime = 2;

    Data.fade.color = COLOR(60, 60, 60);
    Data.fade.speed = 255*2;

    Data.map.fileName = "assets\\map1.txt";
    Data.map.chipSize = 50;
    Data.map.centerX = width / 2 - Data.map.chipSize / 2;

    Data.playerChara.charaId = MAP::PLAYER_ID;
    Data.playerChara.initHp = 1;
    Data.playerChara.groupId = 0;//�����O���[�v��0
    Data.playerChara.speed = 3.4f * 60;
    Data.playerChara.offsetLeft = 10.0f;
    Data.playerChara.offsetTop = 1.0f;
    Data.playerChara.offsetRight = 40.0f;
    Data.playerChara.offsetBottom = 49.0f;
    Data.player.rightAnimId = 0;
    Data.player.leftAnimId = 1;
    Data.player.jumpFlag = 0;
    Data.player.initVecUp = -16.0f;
    Data.player.initVecDown = 3.0f;
    Data.player.gravity = 48;
    Data.player.bulletOffsetX = 20.0f;
    Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

    Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
    Data.playerBulletChara.groupId = 0;//�����O���[�v��0 
    Data.playerBulletChara.initHp = 1;
    Data.playerBulletChara.speed = 4.7f*60;
    Data.playerBulletChara.offsetLeft = 20.0f;
    Data.playerBulletChara.offsetTop = 20.0f;
    Data.playerBulletChara.offsetRight = 30.0f;
    Data.playerBulletChara.offsetBottom = 30.0f;
    
    Data.pumpkinChara.charaId = MAP::PUMPKIN_ID;
    Data.pumpkinChara.groupId = 1;//�G�O���[�v��1
    Data.pumpkinChara.initHp = 4;
    Data.pumpkinChara.speed = 1.4f * 60;
    Data.pumpkinChara.offsetLeft = 10.0f;
    Data.pumpkinChara.offsetTop = 12.0f;
    Data.pumpkinChara.offsetRight = 40.0f;
    Data.pumpkinChara.offsetBottom = 40.0f;
    Data.pumpkin.rightAnimId = 0;
    Data.pumpkin.leftAnimId = 1;
    Data.pumpkin.damageInterval = 5*0.016f;
    Data.pumpkin.initVecX = -1;
    Data.pumpkin.initVecY = 0;
    Data.pumpkin.gravity = 0.8f * 60;
    Data.pumpkin.alphaLowVal = 25;
    Data.pumpkin.explosionCharaId = MAP::EXPLOSION_ID;

    Data.batChara.charaId = MAP::BAT_ID;
    Data.batChara.initHp = 10;
    Data.batChara.groupId = 1;//�G�O���[�v��1
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
    Data.bat.bulletCharaId = MAP::BAT_BULLET_ID;
    Data.bat.damageTime = 0;
    Data.bat.damageInterval = 5*0.016f;
    Data.bat.bulletOffsetX = 20.0f;
    Data.bat.alphaLowVal = 25;
    Data.bat.explosionCharaId = MAP::EXPLOSION_ID;

    Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
    Data.batBulletChara.groupId = 1;//�G�O���[�v��1
    Data.batBulletChara.initHp = 1;
    Data.batBulletChara.speed = 4.7f*60;
    Data.batBulletChara.offsetLeft = 20.0f;
    Data.batBulletChara.offsetTop = 20.0f;
    Data.batBulletChara.offsetRight = 30.0f;
    Data.batBulletChara.offsetBottom = 30.0f;

    Data.explosionChara.charaId = MAP::EXPLOSION_ID;
    Data.explosionChara.angle = 1.57f;

    Data.charaMng.numPlayers = 1;
    Data.charaMng.numPlayerBullets = 5;
    Data.charaMng.numPumpkins = 5;
    Data.charaMng.numBats = 5;
    Data.charaMng.numBatBullets = 12;
    Data.charaMng.numExplosions = 2;
}
void CONTAINER::LoadGraphics() {
    Data.stage.backImg = loadImage("assets\\back_wide.png");
    Data.stage.stageClearImg = loadImage("assets\\StageClear.png");
    Data.stage.gameOverImg = loadImage("assets\\GameOver.png");
    
    Data.map.blockImg = loadImage("assets\\block.png");
    Data.map.goalImg = loadImage("assets\\goal.png");
    
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
    Data.pumpkinChara.anims[0]->load(4, "assets\\pumpkinR");
    Data.pumpkinChara.anims[0]->setInterval(0.1f);
    Data.pumpkinChara.anims[1] = new ANIM;
    Data.pumpkinChara.anims[1]->load(4, "assets\\pumpkinL");
    Data.pumpkinChara.anims[1]->setInterval(0.1f);

    Data.batChara.anims = new ANIM * [1];
    Data.batChara.anims[0] = new ANIM;
    Data.batChara.anims[0]->load(4, "assets\\bat");
    Data.batChara.anims[0]->setInterval(0.1f);

    Data.batBulletChara.anims = new ANIM * [1];
    Data.batBulletChara.anims[0] = new ANIM;
    Data.batBulletChara.anims[0]->load(1, "assets\\batBullet");
    Data.batBulletChara.anims[0]->setInterval(0.1f);

    Data.explosionChara.anims = new ANIM * [1];
    Data.explosionChara.anims[0] = new ANIM;
    Data.explosionChara.anims[0]->load(52, "assets\\explosion\\a");
    Data.explosionChara.anims[0]->setInterval(0.032f);
    Data.explosionChara.anims[0]->setStartIdx(16);
    Data.explosionChara.anims[0]->noLoop();
    Data.explosionChara.imgIdx = 16;
}
