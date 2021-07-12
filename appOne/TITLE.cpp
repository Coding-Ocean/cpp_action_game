#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STAGE.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game):
SCENE(game){
}
TITLE::~TITLE(){}
void TITLE::create(){
    Title = game()->container()->data().title;
}
void TITLE::draw(){
    clear();
    rectMode(CORNER);
    image(Title.backImg, 0, 0);
    image(Title.titleImg, 0, 0);
}
void TITLE::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->setCurScene(game()->stage());
    }
}
