#pragma once
#include "CHARACTER.h"
class BAT :
    public CHARACTER
{
public:
    struct DATA {
        float elapsedTime = 0;
        float interval = 0;
        int triggerCnt = 0;
        int triggerInterval = 0;
        int trigger1st = 0;
        int trigger2nd = 0;
        int trigger3rd = 0;
        int trigger4th = 0;
        float bulletOffsetX = 0;
        char bulletCharaId = 0;
        float damageTime = 0;
        float damageInterval = 0;
        char explosionCharaId = 0;
        COLOR damageColor;
        COLOR normalColor;
    };
private:
    DATA Bat;
public:
    BAT(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx , float wy, float vx, float vy);
    void update();
    void damage();
};

