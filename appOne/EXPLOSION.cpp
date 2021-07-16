#include"graphic.h"
#include"rand.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "EXPLOSION.h"
EXPLOSION::EXPLOSION(class GAME* game) :
    CHARACTER(game) {
}
EXPLOSION::~EXPLOSION() {
}
void EXPLOSION::create() {
    Chara = game()->container()->data().explosionChara;
}
void EXPLOSION::update() {
    if (Chara.anims[0]->end()) {
        Chara.hp = 0;
        Chara.imgIdx = game()->container()->data().explosionChara.imgIdx;
        Chara.anims[0]->resetEndFlag();
    }
}
