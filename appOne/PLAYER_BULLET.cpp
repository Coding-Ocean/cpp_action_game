#include"window.h"
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
    Chara = game()->container()->data().playerBulletChara;
}
void PLAYER_BULLET::appear(const VECTOR2& world, const VECTOR2& vec) {
    Chara.world = world;
    Chara.vec = vec;
    Chara.hp = Chara.initHp;
}
void PLAYER_BULLET::update() {
    //�ړ�--------------------------------------------------------------------------
    Chara.world += Chara.vec * (Chara.speed * delta);
    //�}�b�v------------------------------------------------------------------------
    // �e���A�u���b�N�ɓ��������A�܂��́A�E�B���h�E�̊O�ɏo��
    if (game()->map()->collisionCharaRect(wLeft(), wTop(), wRight(), wBottom()) ||
        Chara.world.x < game()->map()->wDispLeft() ||
        Chara.world.x > game()->map()->wDispRight()) {
        Chara.hp = 0;
    }
}

