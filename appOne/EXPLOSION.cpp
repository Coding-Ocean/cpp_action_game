#include"graphic.h"
#include"rand.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "EXPLOSION.h"
void EXPLOSION::create() {
    Chara = game()->container()->data().explosionChara;
    Explosion = game()->container()->data().explosion;
}
void EXPLOSION::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().explosionChara.hp;
    Chara.wx = wx + Explosion.appearOffsetX;
    Chara.wy = wy + Explosion.appearOffsetY;
    Chara.angle = random() % 7 + 0.0f;
    Chara.animData.reset();
}
void EXPLOSION::update() {
    if (Chara.anim->end(Chara.animData)) {
        Chara.hp = 0;
    }
}
