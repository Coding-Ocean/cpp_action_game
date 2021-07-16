#include"window.h"
#include"graphic.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
#include"CHARACTER_MANAGER.h"
MAP::MAP(class GAME* game):
    GAME_OBJECT(game){
}
MAP::~MAP() {
    if (Map.data) { delete[] Map.data; Map.data = 0; }
}
void MAP::create() {
    Map = game()->container()->data().map;
}
void MAP::init() {
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    Map.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    Map.rows = 0;
    Map.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //�ŏ��̍s�̗�
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//�\�����ׂ���
    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//���[���h�̉���
    Map.endWorldX = Map.worldWidth - width;//�\���ł���Ō�̍��W
    Map.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
}
void MAP::update() {
    float vx = game()->characterManager()->player()->wx() - Map.wx - Map.centerX;
    if (vx > 0) {
        Map.wx += vx;
    }
    if (Map.wx > Map.endWorldX) {
        Map.wx = Map.endWorldX;
    }
}
void MAP::draw() {
    int startCol = (int)Map.wx / Map.chipSize;//�\���J�n��
    int endCol = startCol + Map.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map.chipSize * c;
        for (int r = 0; r < Map.rows; r++) {
            float wy = (float)Map.chipSize * r;
            char charaId = Map.data[r * Map.cols + c];
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map.wx;
                float py = wy - Map.wy;
                if     (charaId == '1')image(Map.blockImg, px, py);
                else if(charaId == '2')image(Map.goalImg, px, py);
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                game()->characterManager()->appear(charaId, wx, wy);
                Map.data[r * Map.cols + c] = '.';
            }
        }
    }
}
//�u���b�N�ƃL�����̓����蔻��p�֐��Q---------------------------------------------------
//�@�w�肳�ꂽ���[���h���W( wx wy )���A�u���b�N�̒��ɂ͂����Ă��邩�`�F�b�N����
bool MAP::collisionCheck(float wx, float wy) {
    //���[���h���W����}�b�vData�̗�col�ƍsrow�����߂�
    int col = (int)wx / Map.chipSize;
    int row = (int)wy / Map.chipSize;
    //Data�͈̔͊O�͔���ł��Ȃ��̂ŏ��O
    if ((col < 0) || (col >= Map.cols) || (row < 0) || (row >= Map.rows)) {
        return false;
    }
    //���̋L�q�ō��W���u���b�N�̒��ɓ����Ă��邩����ł���
    if (Map.data[col + row * Map.cols] == '1') {
        return true;
    }
    return false;
}
//�@�u���b�N�ƃL�����̍��ӂ��d�Ȃ��Ă��邩
bool MAP::collisionCharaLeft(float wx, float wy) {
    bool leftTop = collisionCheck(wx, wy);
    bool leftBottom = collisionCheck(wx, wy + Map.chipSize - 1);
    return leftTop || leftBottom;
}
//�@�u���b�N�ƃL�����̉E�ӂ��d�Ȃ��Ă��邩
bool MAP::collisionCharaRight(float wx, float wy) {
    bool rightTop = collisionCheck(wx + Map.chipSize - 1, wy);
    bool rightBottom = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize - 1);
    return rightTop || rightBottom;
}
//�@�u���b�N�ƃL�����̏�ӂ��d�Ȃ��Ă��邩
bool MAP::collisionCharaTop(float wx, float wy) {
    bool topLeft = collisionCheck(wx, wy);
    bool topRight = collisionCheck(wx + Map.chipSize - 1, wy);
    return topLeft || topRight;
}
//�@�u���b�N�ƃL�����̉��ӂ��d�Ȃ��Ă���A�܂��́A�ڂ��Ă��邩�B�����������ƈႤ�I
bool MAP::collisionCharaBottom(float wx, float wy) {
    // wy + Map.chipSize��Check�֐��ɓn�����Ƃɂ��
    // �L�������u���b�N�Ɛڂ��Ă��邩�`�F�b�N�ł���B
    bool bottomLeft = collisionCheck(wx, wy + Map.chipSize);
    bool bottomRight = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize);
    return bottomLeft || bottomRight;
}
//�@�u���b�N�ƒe�̓����蔻��Ɏg�p
bool MAP::collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom) {
    bool rightTop = collisionCheck(wRight, wTop);
    bool rightBottom = collisionCheck(wRight, wBottom);
    bool leftTop = collisionCheck(wLeft, wTop);
    bool leftBottom = collisionCheck(wLeft, wBottom);
    return rightTop || rightBottom || leftTop || leftBottom;
}
//�E�B���h�E����݂̂͂�������p---------------------------------------------------------
float MAP::wDispLeft() {
    return Map.wx - Map.chipSize;
}
float MAP::wDispRight() {
    return Map.wx + width;
}



