#include"graphic.h"
#include "CONTAINER.h"
#include"ANIMS.h"
CONTAINER::~CONTAINER() {
    //１つのアニメーションの開放
    delete Data.explosionChara.anim;
    delete Data.batChara.anim;
    //複数のアニメーションの開放
    delete Data.pumpkinChara.anims;
    delete Data.playerChara.anims;
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
    Data.playerChara.hp = 1;
    Data.playerChara.groupId = 0;//味方グループは0
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
    Data.playerBulletChara.groupId = 0;//味方グループは0 
    Data.playerBulletChara.hp = 1;
    Data.playerBulletChara.speed = 4.7f*60;
    Data.playerBulletChara.offsetLeft = 20.0f;
    Data.playerBulletChara.offsetTop = 20.0f;
    Data.playerBulletChara.offsetRight = 30.0f;
    Data.playerBulletChara.offsetBottom = 30.0f;
    
    Data.pumpkinChara.charaId = MAP::PUMPKIN_ID;
    Data.pumpkinChara.groupId = 1;//敵グループは1
    Data.pumpkinChara.hp = 4;
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
    Data.pumpkin.damageColor = COLOR(255, 0, 0);
    Data.pumpkin.explosionCharaId = MAP::EXPLOSION_ID;

    Data.batChara.charaId = MAP::BAT_ID;
    Data.batChara.hp = 10;
    Data.batChara.groupId = 1;//敵グループは1
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
    Data.bat.explosionCharaId = MAP::EXPLOSION_ID;
    Data.bat.damageColor = COLOR(255, 0, 0, 25);
    Data.bat.normalColor = COLOR(255, 255, 255);

    Data.batBulletChara.charaId = MAP::BAT_BULLET_ID;
    Data.batBulletChara.groupId = 1;//敵グループは1
    Data.batBulletChara.hp = 1;
    Data.batBulletChara.speed = 4.7f*60;
    Data.batBulletChara.offsetLeft = 20.0f;
    Data.batBulletChara.offsetTop = 20.0f;
    Data.batBulletChara.offsetRight = 30.0f;
    Data.batBulletChara.offsetBottom = 30.0f;

    Data.explosionChara.charaId = MAP::EXPLOSION_ID;
    Data.explosionChara.hp = 1;
    Data.explosionChara.color = COLOR(255, 255, 255, 220);
    Data.explosion.appearOffsetX = -25;
    Data.explosion.appearOffsetY = -25;

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
    
    Data.playerBulletChara.img = loadImage("assets\\playerBullet.png");

    Data.batBulletChara.img = loadImage("assets\\batBullet.png");

    //ANIMS 複数のアニメーションセット
    Data.playerChara.anims = new ANIMS("assets\\player");
    Data.playerChara.animData.interval = 0.1f;

    Data.pumpkinChara.anims = new ANIMS("assets\\pumpkin");
    Data.pumpkinChara.animData.interval = 0.1f;

    //ANIM １つのアニメーションセット
    Data.batChara.anim = new ANIM("assets\\bat\\0");
    Data.batChara.animData.interval = 0.1f;

    Data.explosionChara.anim = new ANIM("assets\\explosion\\0");
    Data.explosionChara.anim->noLoop();
    Data.explosionChara.animData.interval = 0.032f;
}
