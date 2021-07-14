#include"graphic.h"
#include"window.h"
#include"ANIM.h"
ANIM::ANIM() {
}
//開放。確保していない時は開放しない。念のため0クリア。など安全な開放をする。
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
    const VECTOR2& pos, float angle, float scale) {
    if (!EndFlag) {
        *elapsedTime += delta;
        if (*elapsedTime >= Interval) {
            *elapsedTime -= Interval;
            (*idx)++;
            if ((*idx) >= NumImages) {
                if (LoopMode) {
                    (*idx) = StartIdx;
                }
                else {
                    EndFlag = true;
                    (*idx)--;
                }
            }
        }
        image(Images[*idx], pos.x, pos.y, angle, scale);
    }
}



