#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
};

