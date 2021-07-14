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
        float alphaLowVal = 0;
        float appearBulletOffsetX = 0;
        static int idx;
    };
private:
    DATA Bat;
public:
    BAT(class GAME* game);
    ~BAT();
    void create();
    void appear(const VECTOR2& world, const VECTOR2& vec);
    void update();
    void damage();
};

