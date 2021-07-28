#pragma once
#include "CHARACTER.h"
class EXPLOSION :
    public CHARACTER
{
public:
    struct DATA {
        float appearOffsetX = 0;
        float appearOffsetY = 0;
    };
private:
    DATA Explosion;
public:
    EXPLOSION(class GAME* game) :CHARACTER(game) {}
    void appear(float wx, float wy, float vx, float vy);
    void create();
    void update();
};

