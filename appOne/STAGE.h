#pragma once
#include "SCENE.h"
class STAGE :
    public SCENE
{
public:
    struct DATA {
        int backImg = 0;
        int stageClearImg = 0;
        int gameOverImg = 0;
    };
private:
    DATA Stage;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};
