#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PUMPKIN.h"
PUMPKIN::PUMPKIN(class GAME* game) :
    CHARACTER(game) {
}
PUMPKIN::~PUMPKIN() {
}
void PUMPKIN::create() {
    Chara = game()->container()->data().pumpkinChara;
    Pumpkin = game()->container()->data().pumpkin;
}
void PUMPKIN::appear(float wx , float wy, float vx, float vy){
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = Chara.initHp;
    Chara.vx = Pumpkin.initVecX;
    Chara.vy = Pumpkin.initVecY;
    Chara.animId = Pumpkin.leftAnimId;
    Pumpkin.damageTime = 0;
    Pumpkin.fallFlag = 0;
}
void PUMPKIN::update(){
    //移動---------------------------------------------------------------------
    // 落下
    if (Pumpkin.fallFlag) {
        Chara.vy += Pumpkin.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    // 現在の位置をとっておく
    float curWorldX = Chara.wx;
    // 左右にうごく
    Chara.wx += Chara.vx * (Chara.speed * delta);

    //マップ-------------------------------------------------------------------
    // ブロックにぶつかったら向きを変える
    if (!Pumpkin.fallFlag) {
        //左に進んでいるとき
        if (Chara.animId == Pumpkin.leftAnimId) {
            if (game()->map()->collisionCharaLeft(Chara.wx, Chara.wy)) {
                Chara.animId = Pumpkin.rightAnimId;
                Chara.vx = -Chara.vx;
                Chara.wx = curWorldX;
            }
        }
        //右に進んでいるとき
        else {
            if (game()->map()->collisionCharaRight(Chara.wx, Chara.wy)) {
                Chara.animId = Pumpkin.leftAnimId;
                Chara.vx = -Chara.vx;
                Chara.wx = curWorldX;
            }
        }
    }
    // 接地チェック（キャラの下にブロックがあるかどうか）
    if (game()->map()->collisionCharaBottom(curWorldX, Chara.wy)) {//接地または埋まっている
        Pumpkin.fallFlag = 0;
        Chara.vy = 0;
        //埋まらないように高さを補正する
        Chara.wy = (int)Chara.wy / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {//接地していない
        Pumpkin.fallFlag = 1;//落とす
    }
    // ウィンドウの外に出たら消す
    if (Chara.wx < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }
    //ダメージを受けたら瞬間だけ透明化する-------------------------------
    if (Pumpkin.damageTime > 0) {
        Pumpkin.damageTime -= delta;
        Chara.color.a = Pumpkin.alphaLowVal;
    }
    else {
        Chara.color.a = 255;
    }
}
void PUMPKIN::damage(){
    if (Chara.hp>0) {
        Pumpkin.damageTime = Pumpkin.damageInterval;
        Chara.hp--;
        if (Chara.hp == 0) {
            game()->characterManager()->appear(Pumpkin.explosionCharaId, Chara.wx, Chara.wy);
        }
    }
}
