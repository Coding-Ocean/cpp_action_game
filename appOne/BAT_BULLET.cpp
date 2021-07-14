#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BAT_BULLET.h"
BAT_BULLET::BAT_BULLET(class GAME* game) :
    CHARACTER(game) {
}
BAT_BULLET::~BAT_BULLET() {
}
void BAT_BULLET::create() {
    Chara = game()->container()->data().batBullet;
}
extern int gCnt = 0;
void BAT_BULLET::appear(const VECTOR2& world, const VECTOR2& vec) {
    Chara.world = world;
    Chara.vec = vec;
    Chara.hp = Chara.initHp;
    gCnt++;
}
void BAT_BULLET::update() {
    //移動--------------------------------------------------------------------------
    Chara.world += Chara.vec * (Chara.speed * delta);
    //マップ------------------------------------------------------------------------
    // 弾が、ブロックに当たった、または、ウィンドウの外に出た
    if (game()->map()->collisionCharaRect(wLeft(), wTop(), wRight(), wBottom()) ||
        Chara.world.x < game()->map()->wDispLeft() || 
        Chara.world.x > game()->map()->wDispRight()) {
        Chara.hp = 0;
    gCnt--;
    }
}
void BAT_BULLET::draw() {
    CHARACTER::draw();
}

