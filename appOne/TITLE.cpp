#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"STAGE.h"
#include"FADE.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game):
SCENE(game){
}
TITLE::~TITLE(){}
void TITLE::create(){
    Title = game()->container()->data().title;
}
void TITLE::init() {
    game()->fade()->inTrigger();
}
void TITLE::draw(){
    clear();
    rectMode(CORNER);
    fill(Title.backColor);
    rect(0, 0, width, height);
    printSize(80);
    fill(255);
    print("Title");
    print("Push 'SPACE' to start");
    game()->fade()->draw();
}
void TITLE::nextScene(){
    if (isTrigger(KEY_SPACE)) {
        game()->fade()->outTrigger();
    }
    if(game()->fade()->outEndFlag()){
        game()->setCurScene(game()->stage());
    }
}
