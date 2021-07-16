#pragma once
#include"SCENE.h"
#include"COLOR.h"
class TITLE :
    public SCENE
{
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    void draw();
    void nextScene();
};
