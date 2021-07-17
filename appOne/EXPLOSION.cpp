#include"graphic.h"
#include"rand.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "EXPLOSION.h"
void EXPLOSION::create() {
    Chara = game()->container()->data().explosionChara;
}
void EXPLOSION::appear(float wx, float wy, float vx, float vy) {
    Chara.hp = 1;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.angle = random() % 7 + 0.0f;
    Chara.imgIdx = game()->container()->data().explosionChara.imgIdx;
    Chara.anims[0]->resetEndFlag();
}
void EXPLOSION::update() {
    if (Chara.anims[0]->end()) {
        Chara.hp = 0;
    }
}
