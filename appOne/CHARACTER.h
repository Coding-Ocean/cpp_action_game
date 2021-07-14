#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
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
        VECTOR2 world;
        VECTOR2 vec;
        float speed = 0;

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
    virtual void appear(const VECTOR2& world, const VECTOR2& vec);
    virtual void update();
    virtual void draw();
    virtual void damage();
    int   hp() { return Chara.hp; }
    int   groupId() { return Chara.groupId; }
    char  charaId() { return Chara.charaId; }
    float wLeft() { return Chara.world.x + Chara.offsetLeft; }
    float wTop() { return Chara.world.y + Chara.offsetTop; }
    float wRight() { return Chara.world.x + Chara.offsetRight; }
    float wBottom() { return Chara.world.y + Chara.offsetBottom; }
    void setImgIdx(int i) { Chara.imgIdx = i; }
};

