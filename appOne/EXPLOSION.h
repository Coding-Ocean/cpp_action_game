#pragma once
#include "CHARACTER.h"
class EXPLOSION :
    public CHARACTER
{
public:
    EXPLOSION(class GAME* game);
    ~EXPLOSION();
    void create();
};

