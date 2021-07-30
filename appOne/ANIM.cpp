#include"graphic.h"
#include"window.h"
#include"ANIM.h"
ANIM::ANIM() {
}

ANIM::ANIM(int numImages, const char* bodyName, float interval){
    load(numImages, bodyName);
    Interval = interval;
}
ANIM::~ANIM() {
    if (Images) { delete[] Images; Images = 0; }
}

//アニメーション画像ファイル名に２桁連番が降ってあることが前提
//(画像枚数、連番無し拡張子無しファイル名)を指定してアニメーションデータをロード
void ANIM::load(int numImages, const char* bodyName, const char* extName) {
    NumImages = numImages;
    Images = new int[NumImages];
    char filename[256];
    for (int i = 0; i < NumImages; i++) {
        sprintf_s(filename, "%s%02d.%s", bodyName, i, extName);
        Images[i] = loadImage(filename);
    }
}

void ANIM::draw(int* idx, float* elapsedTime, 
    float px, float py, float angle, float scale) {
    //idxの更新
    *elapsedTime += delta;
    if (*elapsedTime >= Interval) {
        *elapsedTime -= Interval;
        (*idx)++;
        if (*idx >= NumImages) {
            if (LoopFlag) {
                *idx = 0;
            }
            else {
                //爆発など一回のみ再生する場合
                EndFlag = true;
                (*idx)--;
            }
        }
    }
    //draw
    image(Images[*idx], px, py, angle, scale);
}
