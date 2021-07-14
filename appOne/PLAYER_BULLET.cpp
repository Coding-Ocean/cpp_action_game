#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER_BULLET.h"
PLAYER_BULLET::PLAYER_BULLET(class GAME* game) :
    CHARACTER(game) {
}
PLAYER_BULLET::~PLAYER_BULLET() {
}
void PLAYER_BULLET::create() {
    Chara = game()->container()->data().playerBullet;
}
