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
        float backToTitleTime = 0;
        COLOR backColor;
        COLOR gameOverColor;
        COLOR stageClearColor;
        float logoPx = 0;
        float logoPy = 0;
    };
private:
    DATA Stage;
    void BackGround();
    void Logo(int img, const COLOR& color);
public:
    STAGE(class GAME* game);
    ~STAGE();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};
