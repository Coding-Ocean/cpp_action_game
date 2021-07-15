#pragma once
#include "CHARACTER.h"
class PUMPKIN :
    public CHARACTER
{
public:
    struct DATA {
        int   rightAnimId = 0;
        int   leftAnimId = 1;
        int   fallFlag = 0;
        float initVecX = 0;
        float initVecY = 0;
        float gravity = 0;
        float alphaLowVal = 0;
        float damageTime = 0;
        float damageInterval = 0;
    };
private:
    DATA Pumpkin;
public:
    PUMPKIN(class GAME* game);
    ~PUMPKIN();
    void create();
    void appear(const VECTOR2& world, const VECTOR2& vec);
    void update();
    void damage();
};

