#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BAT_BULLET.h"
void BAT_BULLET::create() {
    Chara = game()->container()->data().batBulletChara;
}
void BAT_BULLET::appear(float wx , float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().batBulletChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
}
void BAT_BULLET::update() {
    //�ړ�--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta);
    //�}�b�v------------------------------------------------------------------------
    // �e���A�}�b�v�`�b�v�ɓ��������A�܂��́A�E�B���h�E�̊O�ɏo��
    if (game()->map()->collisionCharaRect(wLeft(), wTop(), wRight(), wBottom()) ||
        Chara.wx < game()->map()->wDispLeft() || 
        Chara.wx > game()->map()->wDispRight()) {
        Chara.hp = 0;
    }
}

