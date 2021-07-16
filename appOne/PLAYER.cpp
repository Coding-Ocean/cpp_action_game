#include"window.h"
#include"input.h"
#include"graphic.h"
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
void PLAYER::appear(float wx , float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = Chara.initHp;
    Chara.animId = Player.rightAnimId;
    Player.jumpFlag = 0;
    State = STATE_STRUGGLING;
}
void PLAYER::update() {
    //弾発射-------------------------------------------------------------------
    if (isTrigger(KEY_J)) {
        float vx = 1.0f;
        if (Chara.animId == Player.leftAnimId) vx = -1.0f;
        float wx = Chara.wx + Player.bulletOffsetX * vx;
        float wy = Chara.wy;
        game()->characterManager()->appear(Player.bulletCharaId, wx, wy, vx);
    }
    //移動---------------------------------------------------------------------
    //ジャンプ
    if (!Player.jumpFlag && isTrigger(KEY_K)) {
        Chara.vy = Player.initVecUp;
        Player.jumpFlag = 1;
    }
    if (Player.jumpFlag) {
        Chara.vy += Player.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    //左右移動
    //移動ベクトルを決定
    Chara.vx = 0.0f;
    if (isPress(KEY_A)) {
        Chara.vx = -Chara.speed * delta;
        Chara.animId = Player.leftAnimId;
    }
    if (isPress(KEY_D)) {
        Chara.vx = Chara.speed * delta;
        Chara.animId = Player.rightAnimId;
    }
    //移動前に現在のChara.wxをcurrentWxにとっておく
    float currentWx = Chara.wx;
    if (Chara.vx != 0.0f) {//左右キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のcurrentWxに戻す
        Chara.wx += Chara.vx;
    }
    else {//左右キー入力がないとき
        Chara.imgIdx = 0;
        Chara.elapsedTime = 0;
    }
    //マップ-------------------------------------------------------------------
    // 当たり判定_ブロックとキャラの右
    if (Chara.animId == Player.rightAnimId) {
        if (game()->map()->collisionCharaRight(Chara.wx, Chara.wy)) {
            //移動予定位置がマップに食い込んでいるので現在の位置に戻す
            Chara.wx = currentWx;
        }
    }
    // 当たり判定_ブロックとキャラの左
    else {
        if (game()->map()->collisionCharaLeft(Chara.wx, Chara.wy) ||
            Chara.wx < game()->map()->wx() //または、ウィンドウの左にぶつかったか
            ) {
            Chara.wx = currentWx;
        }
    }
    // 当たり判定_ブロックとキャラの上
    if (game()->map()->collisionCharaTop(Chara.wx, Chara.wy)) {
        Chara.vy = Player.initVecDown;//落ちていく初速度
    }
    // 当たり判定_ブロックとキャラの下
    if (game()->map()->collisionCharaBottom(currentWx, Chara.wy)) {
        //--ブロックに食い込んでいる、または、「上に立っているとき」もここを通る--
        //ジャンプ（落下）処理の停止
        Player.jumpFlag = 0;
        Chara.vy = 0.0f;
        //強制的に上に立っている位置にする
        Chara.wy = (int)Chara.wy / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {
        Player.jumpFlag = 1;//落ちてくトリガー。このフラッグを立てるだけで落ちていく。
    }
    //ステージクリアした-------------------------------------------------------
    if (Chara.wx > game()->map()->wDispRight()) {
        State = STATE_SURVIVED;
        Chara.hp = 0;
    }
    //画面の下に落ちた
    if (Chara.wy > height + game()->map()->chipSize()) {
        State = STATE_FALL;
        Chara.hp = 0;
    }
}
void PLAYER::damage() {
    if (Chara.hp > 0) {
        Chara.hp--;
        if (Chara.hp == 0) {
            State = STATE_DIED;
            Chara.vy = Player.initVecUp;//はね始めのトリガー
        }
    }
}
bool PLAYER::died() {
    if (State == STATE_DIED) {
        Chara.vy += Player.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
        draw();
        return true;
    }
    else if (State == STATE_FALL) {
        return true;
    }
    return false;
}
