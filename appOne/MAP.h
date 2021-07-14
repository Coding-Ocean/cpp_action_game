#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        int blockImg = 0; //�摜�ԍ�
        int chipSize = 0; //�����`�u���b�N�摜�̈�ӂ̃h�b�g��
        char* data = 0; //�f�[�^�z��̃|�C���^
        int cols = 0; //�f�[�^�̗�
        int rows = 0; //�f�[�^�̍s��
        int dispCols = 0;
        int dispRows = 0;
        VECTOR2 world;
        float worldWidth = 0;
        float worldHeight = 0;
        float endWorldX = 0;
        float endWorldY = 0;
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void update();
    void draw();
    VECTOR2 world() { return Map.world; }
    int chipSize() { return Map.chipSize; }
    //�u���b�N�ƃL�����̓����蔻��Ɏg�p����֐��Q---------------------------------------
    bool collisionCheck(float wx, float wy);//���̓����蔻��֐��Q����Ăяo���Ďg���֐�
    bool collisionCharaLeft(float wx, float wy);
    bool collisionCharaRight(float wx, float wy);
    bool collisionCharaTop(float wx, float wy);
    bool collisionCharaBottom(float wx, float wy);
    bool collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom);//�e�p
    //�E�B���h�E�g����݂̂͂�������p---------------------------------------------------
    float wDispLeft();
    float wDispRight();
};

