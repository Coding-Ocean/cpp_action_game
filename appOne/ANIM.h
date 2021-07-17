#pragma once
#include"VECTOR2.h"
class ANIM{
private:
    int NumImages = 0;    //‰æ‘œ–‡”
    int* Images = 0;      //‰æ‘œ”Ô†”z—ñ
    float Interval = 1; //‰æ‘œØ‚è‘Ö‚¦ŠÔŠu
    int LoopFlag = 1;
    bool EndFlag = false;
public:
    ANIM();
    ANIM(int numImages, const char* bodyName, float interval);
    ~ANIM();
    void load(int numImages, const char* bodyName, const char* extName="png");
    void draw(int* idx, float* elapsed, float px, float py, float angle=0, float scale=1 );
    void setInterval(float interval) { Interval = interval; }
    void resetEndFlag() { EndFlag = false; }
    void noLoop() { LoopFlag = 0; }
    bool end() { return EndFlag; }
};

