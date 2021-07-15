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
        Chara.imgIdx = 24;
        Chara.anims[0]->setEndFlag();
    }
}