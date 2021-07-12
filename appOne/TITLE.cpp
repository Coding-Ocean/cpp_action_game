#include"graphic.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game):
SCENE(game){
}
TITLE::~TITLE(){}
void TITLE::create(){
}
void TITLE::draw(){
    clear();
    rectMode(CORNER);
    image(Title.img, 0, 0);
}
void TITLE::nextScene(){
}
