#pragma once
#include "CHARACTER.h"
class PLAYER_BULLET :
    public CHARACTER
{
public:
    PLAYER_BULLET(class GAME* game);
    ~PLAYER_BULLET();
    void create();
    void appear(const VECTOR2& world, const VECTOR2& vec);
    void update();
};

