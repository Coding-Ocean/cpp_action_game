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
}
