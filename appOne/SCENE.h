#pragma once
#include "GAME_OBJECT.h"
class SCENE :
    public GAME_OBJECT
{
public:
    SCENE(class GAME* game);
    virtual ~SCENE();
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void update();
    virtual void draw();
    virtual void nextScene();
};

