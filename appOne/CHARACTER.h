#pragma once
#include"GAME_OBJECT.h"
#include"COLOR.h"
class CHARACTER :
    public GAME_OBJECT
{
public:
    struct DATA {
        class ANIM** anims = 0;
        int animId = 0;
        int imgIdx = 0;
        float elapsedTime = 0;
        COLOR color;

        char charaId = 0;
        int groupId = 0;
        float wx = 0;
        float wy = 0;
        float vx = 0;
        float vy = 0;
        float speed = 0;
        float angle = 0;
        float scale = 1;

        int hp = 0;
        int initHp = 0;
        float offsetLeft = 0;
        float offsetTop = 0;
        float offsetRight = 0;
        float offsetBottom = 0;
    };
protected:
    DATA Chara;
public:
    CHARACTER(class GAME* game);
    virtual ~CHARACTER();
    virtual void create();
    virtual void init();
    virtual void appear(float wx , float wy, float vx, float vy);
    virtual void update();
    virtual void draw();
    virtual void damage();
    int   hp() { return Chara.hp; }
    int   groupId() { return Chara.groupId; }
    char  charaId() { return Chara.charaId; }
    float wLeft() { return Chara.wx + Chara.offsetLeft; }
    float wTop() { return Chara.wy + Chara.offsetTop; }
    float wRight() { return Chara.wx + Chara.offsetRight; }
    float wBottom() { return Chara.wy + Chara.offsetBottom; }
    void setImgIdx(int i) { Chara.imgIdx = i; }
};

