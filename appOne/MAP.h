#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
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
        int dispRows = 0;
        VECTOR2 world;
        float worldWidth = 0;
        float worldHeight = 0;
        float endWorldX = 0;
        float endWorldY = 0;
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void update();
    void draw();
    VECTOR2 world() { return Map.world; }
    int chipSize() { return Map.chipSize; }
    //ブロックとキャラの当たり判定に使用する関数群---------------------------------------
    bool collisionCheck(float wx, float wy);//下の当たり判定関数群から呼び出して使う関数
    bool collisionCharaLeft(float wx, float wy);
    bool collisionCharaRight(float wx, float wy);
    bool collisionCharaTop(float wx, float wy);
    bool collisionCharaBottom(float wx, float wy);
    bool collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom);//弾用
    //ウィンドウ枠からのはみだし判定用---------------------------------------------------
    float wDispLeft();
    float wDispRight();
};

