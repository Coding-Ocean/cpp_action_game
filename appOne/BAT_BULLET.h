#pragma once
#include "CHARACTER.h"
class BAT_BULLET :
    public CHARACTER
{
public:
    BAT_BULLET(class GAME* game);
    ~BAT_BULLET();
    void create();
    void appear(float wx , float wy, float vx, float vy);
    void update();
};

