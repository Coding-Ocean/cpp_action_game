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
