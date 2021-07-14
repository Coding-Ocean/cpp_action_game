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
    Chara = game()->container()->data().explosion;
}
