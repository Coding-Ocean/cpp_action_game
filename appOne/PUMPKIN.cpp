#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PUMPKIN.h"
PUMPKIN::PUMPKIN(class GAME* game) :
    CHARACTER(game) {
}
PUMPKIN::~PUMPKIN() {
}
void PUMPKIN::create() {
    Chara = game()->container()->data().pumpkinChara;
    Pumpkin = game()->container()->data().pumpkin;
}
void PUMPKIN::appear(float wx , float wy, float vx, float vy){
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = Chara.initHp;
    Chara.vx = Pumpkin.initVecX;
    Chara.vy = Pumpkin.initVecY;
    Chara.animId = Pumpkin.leftAnimId;
    Pumpkin.damageTime = 0;
    Pumpkin.fallFlag = 0;
}
void PUMPKIN::update(){
    //�ړ�---------------------------------------------------------------------
    // ����
    if (Pumpkin.fallFlag) {
        Chara.vy += Pumpkin.gravity * delta;
        Chara.wy += Chara.vy * 60 * delta;
    }
    // ���݂̈ʒu���Ƃ��Ă���
    float curWorldX = Chara.wx;
    // ���E�ɂ�����
    Chara.wx += Chara.vx * (Chara.speed * delta);

    //�}�b�v-------------------------------------------------------------------
    // �u���b�N�ɂԂ������������ς���
    if (!Pumpkin.fallFlag) {
        //���ɐi��ł���Ƃ�
        if (Chara.animId == Pumpkin.leftAnimId) {
            if (game()->map()->collisionCharaLeft(Chara.wx, Chara.wy)) {
                Chara.animId = Pumpkin.rightAnimId;
                Chara.vx = -Chara.vx;
                Chara.wx = curWorldX;
            }
        }
        //�E�ɐi��ł���Ƃ�
        else {
            if (game()->map()->collisionCharaRight(Chara.wx, Chara.wy)) {
                Chara.animId = Pumpkin.leftAnimId;
                Chara.vx = -Chara.vx;
                Chara.wx = curWorldX;
            }
        }
    }
    // �ڒn�`�F�b�N�i�L�����̉��Ƀu���b�N�����邩�ǂ����j
    if (game()->map()->collisionCharaBottom(curWorldX, Chara.wy)) {//�ڒn�܂��͖��܂��Ă���
        Pumpkin.fallFlag = 0;
        Chara.vy = 0;
        //���܂�Ȃ��悤�ɍ�����␳����
        Chara.wy = (int)Chara.wy / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {//�ڒn���Ă��Ȃ�
        Pumpkin.fallFlag = 1;//���Ƃ�
    }
    // �E�B���h�E�̊O�ɏo�������
    if (Chara.wx < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }
    //�_���[�W���󂯂���u�Ԃ�������������-------------------------------
    if (Pumpkin.damageTime > 0) {
        Pumpkin.damageTime -= delta;
        Chara.color.a = Pumpkin.alphaLowVal;
    }
    else {
        Chara.color.a = 255;
    }
}
void PUMPKIN::damage(){
    if (Chara.hp>0) {
        Pumpkin.damageTime = Pumpkin.damageInterval;
        Chara.hp--;
        if (Chara.hp == 0) {
            game()->characterManager()->appear(Pumpkin.explosionCharaId, Chara.wx, Chara.wy);
        }
    }
}
