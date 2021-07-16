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
TITLE::~TITLE(){
}
void TITLE::init() {
    game()->fade()->inTrigger();
}
void TITLE::draw(){
    clear();
    rectMode(CORNER);
    imageColor(240);
    image(game()->container()->data().stage.backImg, 0, 0);
    float size;

    size = 50;
    textSize(size);
    fill(0);
    text("クッキー王子の", (width - size * 7) / 2 + 2, 80+2);
    size = 90;
    textSize(size);
    text("お菓子なハロウィン", (width - size * 9) / 2 +2, 185+2);
    size = 50;
    textSize(size);
    text("A⇔D...Move  ", (width - size / 2 * 13) / 2+2, 290+2);
    text("J......Launch", (width - size / 2 * 13) / 2+2, 360+2);
    text("K......Jump  ", (width - size / 2 * 13) / 2+2, 430+2);
    text("Push 'SPACE' to start", (width - size / 2 * 21) / 2+2, 550+2);

    size = 50;
    textSize(size);
    fill(255, 255, 0);
    text("クッキー王子の", (width - size * 7) / 2, 80);
    size = 90;
    textSize(size);
    text("お菓子なハロウィン", (width - size * 9) / 2, 185);
    size = 50;
    textSize(size);
    fill(255);
    text("A⇔D...Move  ", (width - size / 2 * 13) / 2, 290);
    text("J......Launch", (width - size / 2 * 13) / 2, 360);
    text("K......Jump  ", (width - size / 2 * 13) / 2, 430);
    fill(255,0,255);
    text("Push 'SPACE' to start",(width - size / 2 * 21) / 2, 550);

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
