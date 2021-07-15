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
void PUMPKIN::appear(const VECTOR2& world, const VECTOR2& vec){
    Chara.world = world;
    Chara.hp = Chara.initHp;
    Chara.vec.x = Pumpkin.initVecX;
    Chara.vec.y = Pumpkin.initVecY;
    Chara.animId = Pumpkin.leftAnimId;
    Pumpkin.damageTime = 0;
    Pumpkin.fallFlag = 0;
}
void PUMPKIN::update(){
    //�ړ�---------------------------------------------------------------------
    // ����
    if (Pumpkin.fallFlag) {
        Chara.vec.y += Pumpkin.gravity * delta;
        Chara.world.y += Chara.vec.y;
    }
    // ���݂̈ʒu���Ƃ��Ă���
    float curWorldX = Chara.world.x;
    // ���E�ɂ�����
    Chara.world.x += Chara.vec.x * (Chara.speed * delta);

    //�}�b�v-------------------------------------------------------------------
    // �u���b�N�ɂԂ������������ς���
    if (!Pumpkin.fallFlag) {
        //���ɐi��ł���Ƃ�
        if (Chara.animId == Pumpkin.leftAnimId) {
            if (game()->map()->collisionCharaLeft(Chara.world.x, Chara.world.y)) {
                Chara.animId = Pumpkin.rightAnimId;
                Chara.vec.x = -Chara.vec.x;
                Chara.world.x = curWorldX;
            }
        }
        //�E�ɐi��ł���Ƃ�
        else {
            if (game()->map()->collisionCharaRight(Chara.world.x, Chara.world.y)) {
                Chara.animId = Pumpkin.leftAnimId;
                Chara.vec.x = -Chara.vec.x;
                Chara.world.x = curWorldX;
            }
        }
    }
    // �ڒn�`�F�b�N�i�L�����̉��Ƀu���b�N�����邩�ǂ����j
    if (game()->map()->collisionCharaBottom(curWorldX, Chara.world.y)) {//�ڒn�܂��͖��܂��Ă���
        Pumpkin.fallFlag = 0;
        Chara.vec.y = 0;
        //���܂�Ȃ��悤�ɍ�����␳����
        Chara.world.y = (int)Chara.world.y / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {//�ڒn���Ă��Ȃ�
        Pumpkin.fallFlag = 1;//���Ƃ�
    }
    // �E�B���h�E�̊O�ɏo�������
    if (Chara.world.x < game()->map()->wDispLeft()) {
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
            game()->characterManager()->appear('f', Chara.world, VECTOR2(0, 0));
        }
    }
}
