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
void PUMPKIN::appear(const VECTOR2& world, const VECTOR2& vec){
    Chara.world = world;
    Chara.hp = Chara.initHp;
    Chara.vec.x = Pumpkin.initVecX;
    Chara.vec.y = Pumpkin.initVecY;
    Chara.animId = Pumpkin.leftAnimId;
    Pumpkin.damageTime = 0;
    Pumpkin.fallFlag = 0;
}
void PUMPKIN::update(){
    //移動---------------------------------------------------------------------
    // 落下
    if (Pumpkin.fallFlag) {
        Chara.vec.y += Pumpkin.gravity * delta;
        Chara.world.y += Chara.vec.y;
    }
    // 現在の位置をとっておく
    float curWorldX = Chara.world.x;
    // 左右にうごく
    Chara.world.x += Chara.vec.x * (Chara.speed * delta);

    //マップ-------------------------------------------------------------------
    // ブロックにぶつかったら向きを変える
    if (!Pumpkin.fallFlag) {
        //左に進んでいるとき
        if (Chara.animId == Pumpkin.leftAnimId) {
            if (game()->map()->collisionCharaLeft(Chara.world.x, Chara.world.y)) {
                Chara.animId = Pumpkin.rightAnimId;
                Chara.vec.x = -Chara.vec.x;
                Chara.world.x = curWorldX;
            }
        }
        //右に進んでいるとき
        else {
            if (game()->map()->collisionCharaRight(Chara.world.x, Chara.world.y)) {
                Chara.animId = Pumpkin.leftAnimId;
                Chara.vec.x = -Chara.vec.x;
                Chara.world.x = curWorldX;
            }
        }
    }
    // 接地チェック（キャラの下にブロックがあるかどうか）
    if (game()->map()->collisionCharaBottom(curWorldX, Chara.world.y)) {//接地または埋まっている
        Pumpkin.fallFlag = 0;
        Chara.vec.y = 0;
        //埋まらないように高さを補正する
        Chara.world.y = (int)Chara.world.y / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {//接地していない
        Pumpkin.fallFlag = 1;//落とす
    }
    // ウィンドウの外に出たら消す
    if (Chara.world.x < game()->map()->wDispLeft()) {
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
            game()->characterManager()->appear('f', Chara.world, VECTOR2(0, 0));
        }
    }
}
