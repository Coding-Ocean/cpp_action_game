#pragma once
#include"ANIM.h"
class ANIMS{
private:
    int NumAnims = 0;
    class ANIM** Anims = 0;
public:
    ANIMS();
    ANIMS(const char* path);
    ANIMS(const char* fileName, int cols, int rows, int w, int h);
    ~ANIMS();
    void load(const char* path);
    void load(const char* fileName, int cols, int rows,int w, int h);
    //getter
    class ANIM* anim(int animIdx);
};

