#include"window.h"
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
    Chara = game()->container()->data().batBulletChara;
}
void BAT_BULLET::appear(float wx , float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.hp = Chara.initHp;
}
void BAT_BULLET::update() {
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

