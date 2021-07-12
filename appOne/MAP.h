#pragma once
#include "GAME_OBJECT.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        int blockImg = 0; //画像番号
        int chipSize = 0; //正方形ブロック画像の一辺のドット数
        char* data = 0; //データ配列のポインタ
        int cols = 0; //データの列数
        int rows = 0; //データの行数
        int dispCols = 0;
        float worldX = 0;
        float worldWidth = 0;
        float endWorldX = 0;
    };
private:
    DATA Map;
    void load();
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void update();
    void draw();
};

