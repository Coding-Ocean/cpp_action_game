#include"window.h"
#include"input.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER.h"
PLAYER::PLAYER(class GAME* game) :
    CHARACTER(game) {
}
PLAYER::~PLAYER() {
}
void PLAYER::create() {
    Chara = game()->container()->data().playerChara;
    Player = game()->container()->data().player;
}
void PLAYER::appear(const VECTOR2& world, const VECTOR2& vec) {
    Chara.world = world;
    Chara.hp = Chara.initHp;
    Chara.animId = Player.rightAnimId;
    Player.jumpFlag = 0;
    State = STATE_STRUGGLING;
}
void PLAYER::update() {
    //�X�e�[�W�N���A����-------------------------------------------------------
    if (Chara.world.x > game()->map()->wDispRight()) {
        State = STATE_SURVIVED;
        return;
    }
    //�e����-------------------------------------------------------------------
    if (isTrigger(KEY_K)) {
        float vx = 1.0f, vy = 0;
        if (Chara.animId == Player.leftAnimId) vx = -1.0f;
        game()->characterManager()->appear( Player.bulletCharaId, 
            VECTOR2(Chara.world.x + Player.bulletOffsetX * vx, Chara.world.y), 
            VECTOR2(vx, vy));
    }
    //�ړ�---------------------------------------------------------------------
    //�W�����v
    if (!Player.jumpFlag && isTrigger(KEY_J)) {
        Chara.vec.y = Player.initVecUp;
        Player.jumpFlag = 1;
    }
    if (Player.jumpFlag) {
        Chara.vec.y += Player.gravity * delta;
        Chara.world.y += Chara.vec.y;
    }
    //���E�ړ�
    //�ړ��x�N�g��������
    Chara.vec.x = 0.0f;
    if (isPress(KEY_A)) {
        Chara.vec.x = -Chara.speed * delta;
        Chara.animId = Player.leftAnimId;
    }
    if (isPress(KEY_D)) {
        Chara.vec.x = Chara.speed * delta;
        Chara.animId = Player.rightAnimId;
    }
    //�ړ��O�Ɍ��݂�Chara.world.x��currentWx�ɂƂ��Ă���
    float currentWx = Chara.world.x;
    if (Chara.vec.x != 0.0f) {//���E�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.world.x���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����currentWx�ɖ߂�
        Chara.world.x += Chara.vec.x;
    }
    else {//���E�L�[���͂��Ȃ��Ƃ�
        Chara.imgIdx = 0;
        Chara.elapsedTime = 0;
    }
    //�}�b�v-------------------------------------------------------------------
    // �����蔻��_�u���b�N�ƃL�����̉E
    if (Chara.animId == Player.rightAnimId) {
        if (game()->map()->collisionCharaRight(Chara.world.x, Chara.world.y)) {
            //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
            Chara.world.x = currentWx;
        }
    }
    // �����蔻��_�u���b�N�ƃL�����̍�
    else {
        if (game()->map()->collisionCharaLeft(Chara.world.x, Chara.world.y) ||
            Chara.world.x < game()->map()->world().x //�܂��́A�E�B���h�E�̍��ɂԂ�������
            ) {
            Chara.world.x = currentWx;
        }
    }
    // �����蔻��_�u���b�N�ƃL�����̏�
    if (game()->map()->collisionCharaTop(Chara.world.x, Chara.world.y)) {
        Chara.vec.y = Player.initVecDown;//�����Ă��������x
    }
    // �����蔻��_�u���b�N�ƃL�����̉�
    if (game()->map()->collisionCharaBottom(currentWx, Chara.world.y)) {
        //--�u���b�N�ɐH������ł���A�܂��́A�u��ɗ����Ă���Ƃ��v��������ʂ�--
        //�W�����v�i�����j�����̒�~
        Player.jumpFlag = 0;
        Chara.vec.y = 0.0f;
        //�����I�ɏ�ɗ����Ă���ʒu�ɂ���
        Chara.world.y = (int)Chara.world.y / game()->map()->chipSize() * (float)game()->map()->chipSize();
    }
    else {
        Player.jumpFlag = 1;//�����Ă��g���K�[�B���̃t���b�O�𗧂Ă邾���ŗ����Ă����B
    }
    // �X�N���[���BPlayer���E�B���h�E�̒����𒴂����������X�N���[��������
    if (Chara.vec.x != 0) {
        float overCenterX = Chara.world.x - game()->map()->world().x - Player.centerX;
        if (overCenterX > 0) {
            game()->map()->update(overCenterX);
        }
    }
}
void PLAYER::damage() {
    if (Chara.hp > 0) {
        Chara.hp--;
        if (Chara.hp == 0) {
            //if (State == STATE_STRUGGLING) {
                State = STATE_DIED;
                Chara.vec.y = Player.initVecUp;//�͂ˎn�߂̃g���K�[
            //}
        }
    }
}
bool PLAYER::died() {
    if (State == STATE_DIED) {
        Chara.vec.y += Player.gravity * delta;
        Chara.world.y += Chara.vec.y;
        draw();
        return true;
    }
    return false;
}
