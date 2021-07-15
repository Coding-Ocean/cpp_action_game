#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PUMPKIN.h"
PUMPKIN::PUMPKIN(class GAME* game) :
    CHARACTER(game) {
}
PUMPKIN::~PUMPKIN() {
}
void PUMPKIN::create() {
    Chara = game()->container()->data().pumpkinChara;
}
