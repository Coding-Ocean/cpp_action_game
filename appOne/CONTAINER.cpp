#include"graphic.h"
#include "CONTAINER.h"
void CONTAINER::load() {
    setData();
    loadGraphics();
}
void CONTAINER::setData() {
}
void CONTAINER::loadGraphics() {
    int backImg = loadImage("assets\\back.png");
    Data.title.backImg = backImg;
    Data.title.titleImg = loadImage("assets\\title.png");
}
