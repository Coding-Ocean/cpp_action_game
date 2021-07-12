#pragma once
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        int backImg = 0;
        int titleImg = 0;
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void draw();
    void nextScene();
};
