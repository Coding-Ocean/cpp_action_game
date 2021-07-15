#include"window.h"
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
    Chara = game()->container()->data().batChara;
    Bat = game()->container()->data().bat;
}
void BAT::appear(const VECTOR2& world, const VECTOR2& vec) {
    Chara.world = world;
    Chara.vec = vec;
    Chara.hp = Chara.initHp;
    Bat.triggerCnt = game()->container()->data().bat.triggerCnt;
}
void BAT::update() {
    //��������e����----------------------------------------------------------------
    Bat.elapsedTime += delta;
    if (Bat.elapsedTime >= Bat.interval) {
        Bat.elapsedTime -= Bat.interval;
        ++Bat.triggerCnt %= Bat.triggerInterval;
        if (Bat.triggerCnt == Bat.trigger1st ||
            Bat.triggerCnt == Bat.trigger2nd ||
            Bat.triggerCnt == Bat.trigger3rd ||
            Bat.triggerCnt == Bat.trigger4th
            ) {
            game()->characterManager()->appear(Bat.bulletCharaId,
                VECTOR2(Chara.world.x - Bat.bulletOffsetX, Chara.world.y),
                VECTOR2(-1, 0));
        }
    }

    //�}�b�v------------------------------------------------------------------------
    // �E�B���h�E�̊O�ɏo��
    if (Chara.world.x < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }

    //�_���[�W���󂯂��琔�t���[����������������------------------------------------
    if (Bat.damageTime > 0) {
        Bat.damageTime -= delta;
        Chara.color.a = Bat.alphaLowVal;
    }
    else {
        Chara.color.a = 255;
        Bat.damageTime = 0;
    }
}
void BAT::damage() {
    if (Chara.hp > 0) {
        Bat.damageTime = Bat.damageInterval;
        Chara.hp--;
        if (Chara.hp == 0) {
            game()->characterManager()->appear('f', Chara.world, VECTOR2(0, 0));
        }
    }
}
