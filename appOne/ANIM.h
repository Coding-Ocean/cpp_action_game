#pragma once
#include"VECTOR2.h"
class ANIM{
private:
    int NumImages = 0;    //�摜����
    int* Images = 0;      //�摜�ԍ��z��
    float Interval = 1; //�摜�؂�ւ��Ԋu
    int LoopMode = 1;
    bool EndFlag = false;
    int StartIdx = 0;
public:
    ANIM();
    ~ANIM();
    void load(int numImages, const char* bodyName, const char* extName="png");
    void draw(int* idx, float* elapsed, const VECTOR2& pos, float angle=0, float scale=1 );
    void noLoop() { LoopMode = 0; }
    void setStartIdx(int idx) { StartIdx = idx; }
    bool end() { return EndFlag; }
    void setInterval(float interval) { Interval = interval; }
};

