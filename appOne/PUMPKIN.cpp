#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PUMPKIN.h"
void PUMPKIN::create() {
    Chara = game()->container()->data().pumpkinChara;
    Pumpkin = game()->container()->data().pumpkin;
}
void PUMPKIN::appear(float wx , float wy, float vx, float vy){
    Chara.hp = game()->container()->data().pumpkinChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = Pumpkin.initVecX;
    Chara.vy = Pumpkin.initVecY;
    Chara.animId = Pumpkin.leftAnimId;
    Pumpkin.damageTime = 0;
    Pumpkin.fallFlag = 0;
}
void PUMPKIN::update(){
    Move();
    CollisionWithMap();
    ChangeColor();
}
void PUMPKIN::Move(){
    //落下
    if (Pumpkin.fallFlag) {
        Chara.vy += Pumpkin.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    //現在の位置をとっておく
    Pumpkin.curWx = Chara.wx;
    //左右にうごく
    Chara.wx += Chara.vx * (Chara.speed * delta);
}
void PUMPKIN::CollisionWithMap(){
    MAP* map = game()->map();
    // マップチップにぶつかったら向きを変える
    if (Pumpkin.fallFlag==0) {
        if (map->collisionCharaLeft(Chara.wx, Chara.wy) ||
            map->collisionCharaRight(Chara.wx, Chara.wy)) {
            Chara.animId = 1 - Chara.animId;
            Chara.vx = -Chara.vx;
            Chara.wx = Pumpkin.curWx;
        }
    }
    // 接地チェック（キャラの下にマップチップがあるかどうか）
    if (map->collisionCharaBottom(Pumpkin.curWx, Chara.wy)) {
        //接地または埋まっている
        Pumpkin.fallFlag = 0;
        Chara.vy = 0;
        //埋まらないように高さを補正する
        Chara.wy = (int)Chara.wy / map->chipSize() * (float)map->chipSize();
    }
    else {//接地していない
        Pumpkin.fallFlag = 1;//落とす
    }
    // ウィンドウの外に出た
    if (Chara.wx < map->wDispLeft()) {
        Chara.hp = 0;
    }
}
void PUMPKIN::ChangeColor(){
    //ダメージを受けたら瞬間だけ色を変える
    if (Pumpkin.damageTime > 0) {
        Pumpkin.damageTime -= delta;
        Chara.color = Pumpkin.damageColor;
    }
    else {
        Chara.color = Pumpkin.normalColor;
    }
}
void PUMPKIN::damage(){
    if (Chara.hp > 0) {
        Pumpkin.damageTime = Pumpkin.damageInterval;
        Chara.hp--;
        if (Chara.hp == 0) {
            game()->characterManager()->appear(Pumpkin.explosionCharaId, 
                Chara.wx, Chara.wy);
        }
    }
}
