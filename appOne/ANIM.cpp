#include"graphic.h"
#include"window.h"
#include"ANIM.h"
ANIM::ANIM() {
}
//�J���B�m�ۂ��Ă��Ȃ����͊J�����Ȃ��B�O�̂���0�N���A�B�Ȃǈ��S�ȊJ��������B
ANIM::~ANIM() {
    if (Images) { delete[] Images; Images = 0; }
}
//�A�j���[�V�����摜�t�@�C�����ɂQ���A�Ԃ��~���Ă��邱�Ƃ��O��
//(�摜�����A�A�Ԗ����g���q�����t�@�C����)���w�肵�ăA�j���[�V�����f�[�^�����[�h
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



