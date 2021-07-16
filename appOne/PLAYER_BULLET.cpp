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
void PLAYER_BULLET::appear(float wx , float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.vy = vy;
    Chara.hp = Chara.initHp;
}
void PLAYER_BULLET::update() {
    //�ړ�--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta);
    //�}�b�v------------------------------------------------------------------------
    // �e���A�u���b�N�ɓ��������A�܂��́A�E�B���h�E�̊O�ɏo��
    if (game()->map()->collisionCharaRect(wLeft(), wTop(), wRight(), wBottom()) ||
        Chara.wx < game()->map()->wDispLeft() ||
        Chara.wx > game()->map()->wDispRight()) {
        Chara.hp = 0;
    }
}
