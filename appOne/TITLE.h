#pragma once
#include"SCENE.h"
#include"COLOR.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void init();
    void draw();
    void nextScene();
};
