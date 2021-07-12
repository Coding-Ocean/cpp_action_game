#include"window.h"
#include"graphic.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
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
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", Map.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //サイズ分のdata配列を用意する
    Map.data = new char[fileSize];
    //データを読み込む
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    Map.rows = 0;
    Map.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //最初の行の列数
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//表示すべき列数
    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//ワールドの横幅
    Map.endWorldX = Map.worldWidth - width;//表示できる最後の座標
    Map.worldX = 0.0f;//現在表示しているワールド座標
}
void MAP::update() {
    Map.worldX += 60 * delta;
    if (Map.worldX > Map.endWorldX) {
        Map.worldX = Map.endWorldX;
    }
}
void MAP::draw() {
    int startCol = (int)Map.worldX / Map.chipSize;//表示開始列
    int endCol = startCol + Map.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float px = -Map.worldX + Map.chipSize * c;
        for (int r = 0; r < Map.rows; r++) {
            float py = (float)Map.chipSize * r;
            switch (Map.data[r * Map.cols + c]) {
            case '1':
                image(Map.blockImg, px, py);
                break;
            default:
                break;
            }
        }
    }
}

