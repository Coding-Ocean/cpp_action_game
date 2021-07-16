#include"window.h"
#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"MAP.h"
#include"CHARACTER_MANAGER.h"
#include "STAGE.h"
STAGE::STAGE(class GAME* game):
SCENE(game){
}
STAGE::~STAGE(){
}
void STAGE::create(){
    Stage = game()->container()->data().stage;
}
void STAGE::init() {
    Stage.backToTitleTime = game()->container()->data().stage.backToTitleTime;
    game()->map()->init();
    game()->characterManager()->init();
    game()->fade()->inTrigger();
}
void STAGE::update() {
    game()->characterManager()->update();
    game()->map()->update();
}
void STAGE::draw(){
    BackGround();
    game()->map()->draw();
    game()->characterManager()->draw();
    if (game()->characterManager()->player()->died()) {
        Logo(Stage.gameOverImg, Stage.gameOverColor);
    }
    else if (game()->characterManager()->player()->survived()) {
        Logo(Stage.stageClearImg, Stage.stageClearColor);
    }
#ifdef _DEBUG
    fill(255);
    printSize(50);
    print(delta);
#endif
    game()->fade()->draw();
}
void STAGE::BackGround(){
    clear();
    rectMode(CORNER);
    imageColor(Stage.backColor);
    image(Stage.backImg, 0, 0);
}
void STAGE::Logo(int img,const COLOR& color) {
    imageColor(color);
    image(img, Stage.logoPx, Stage.logoPy);
    Stage.backToTitleTime -= delta;
}
void STAGE::nextScene() {
    if (Stage.backToTitleTime <= 0) {
        game()->fade()->outTrigger();
    }
    if (game()->fade()->outEndFlag()) {
        game()->setCurScene(game()->title());
    }
}
