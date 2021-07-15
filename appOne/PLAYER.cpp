#include"window.h"
#include"input.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER.h"
PLAYER::PLAYER(class GAME* game) :
    CHARACTER(game) {
}
PLAYER::~PLAYER() {
}
void PLAYER::create() {
    Chara = game()->container()->data().playerChara;
    Player = game()->container()->data().player;
}
void PLAYER::appear(const VECTOR2& world, const VECTOR2& vec) {
    Chara.world = world;
    Chara.hp = Chara.initHp;
    Chara.animId = Player.rightAnimId;
    Player.jumpFlag = 0;
    State = STATE_STRUGGLING;
}
void PLAYER::update() {
    //ステージクリアした-------------------------------------------------------
    if (Chara.world.x > game()->map()->wDispRight()) {
        State = STATE_SURVIVED;
        return;
    }
    //弾発射-------------------------------------------------------------------
    if (isTrigger(KEY_K)) {
        float vx = 1.0f, vy = 0;
        if (Chara.animId == Player.leftAnimId) vx = -1.0f;
        game()->characterManager()->appear( Player.bulletCharaId, 
            VECTOR2(Chara.world.x + Player.bulletOffsetX * vx, Chara.world.y), 
            VECTOR2(vx, vy));
    }
    //移動---------------------------------------------------------------------
    //ジャンプ
    if (!Player.jumpFlag && isTrigger(KEY_J)) {
        Chara.vec.y = Player.initVecUp;
        Player.jumpFlag = 1;
    }
    if (Player.jumpFlag) {
        Chara.vec.y += Player.gravity * delta;
        Chara.world.y += Chara.vec.y;
    }
    //左右移動
    //移動ベクトルを決定
    Chara.vec.x = 0.0f;
    if (isPress(KEY_A)) {
        Chara.vec.x = -Chara.speed * delta;
        Chara.animId = Player.leftAnimId;
    }
    if (isPress(KEY_D)) {
        Chara.vec.x = Chara.speed * delta;
        Chara.animId = Player.rightAnimId;
    }
    //移動前に現在のChara.world.xをcurrentWxにとっておく
    float currentWx = Chara.world.x;
    if (Chara.vec.x != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.world.xを更新しておき
        //あとで、マップに食い込んでいたら、元のcurrentWxに戻す
        Chara.world.x += Chara.vec.x;
    }
    else {//左右キー入力がないとき
        Chara.imgIdx = 0;
        Chara.elapsedTime = 0;
    }
    //マップ-------------------------------------------------------------------
    // 当たり判定_ブロックとキャラの右
    if (Chara.animId == Player.rightAnimId) {
        if (game()->map()->collisionCharaRight(Chara.world.x, Chara.world.y)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.world.x = currentWx;
        }
    }
    // 当たり判定_ブロックとキャラの左
    else {
        if (game()->map()->collisionCharaLeft(Chara.world.x, Chara.world.y) ||
            Chara.world.x < game()->map()->world().x //または、ウィンドウの左にぶつかったか
            ) {
            Chara.world.x = currentWx;
        }
    }
    // 当たり判定_ブロックとキャラの上
    if (game()->map()->collisionCharaTop(Chara.world.x, Chara.world.y)) {
        Chara.vec.y = Player.initVecDown;//落ちていく初速度
    }
    // 当たり判定_ブロックとキャラの下
    if (game()->map()->collisionCharaBottom(currentWx, Chara.world.y)) {
        //--ブロックに食い込んでいる、または、「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Player.jumpFlag = 0;
        Chara.vec.y = 0.0f;
        //強制的に上に立っている位置にする
        Chara.world.y = (int)Chara.world.y / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {
        Player.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
    // スクロール。Playerがウィンドウの中央を超えた分だけスクロールさせる
    if (Chara.vec.x != 0) {
        float overCenterX = Chara.world.x - game()->map()->world().x - Player.centerX;
        if (overCenterX > 0) {
            game()->map()->update(overCenterX);
        }
    }
}
void PLAYER::damage() {
    if (Chara.hp > 0) {
        Chara.hp--;
        if (Chara.hp == 0) {
            //if (State == STATE_STRUGGLING) {
                State = STATE_DIED;
                Chara.vec.y = Player.initVecUp;//はね始めのトリガー
            //}
        }
    }
}
bool PLAYER::died() {
    if (State == STATE_DIED) {
        Chara.vec.y += Player.gravity * delta;
        Chara.world.y += Chara.vec.y;
        draw();
        return true;
    }
    return false;
}
