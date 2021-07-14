#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BAT.h"
BAT::BAT(class GAME* game) :
    CHARACTER(game) {
}
BAT::~BAT() {
}
void BAT::create() {
    Chara = game()->container()->data().bat;
}
