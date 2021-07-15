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
STAGE::~STAGE(){}
void STAGE::create(){
    Stage = game()->container()->data().stage;
}
void STAGE::init() {
    game()->map()->init();
    game()->characterManager()->init();
    game()->fade()->inTrigger();
}
void STAGE::update() {
    game()->characterManager()->update();
}
void STAGE::draw(){
    clear(60,30,0);
    rectMode(CORNER);
    imageColor(255, 255, 255, 255);
    image(Stage.backImg, 0, 0);
    game()->map()->draw();
    game()->characterManager()->draw();

    if (game()->characterManager()->player()->died()) {
        //game()->characterManager()->player()->update();
        //game()->characterManager()->player()->draw();
        imageColor(255, 255, 255, 255);
        image(Stage.gameOverImg, 0, 270);
    }
    if (game()->characterManager()->player()->survived()) {
        imageColor(255, 255, 255, 255);
        image(Stage.stageClearImg, 0, 270);
    }
    game()->fade()->draw();
}
void STAGE::nextScene() {
    if (isTrigger(KEY_SPACE)) {
        game()->fade()->outTrigger();
    }
    if (game()->fade()->outEndFlag()) {
        game()->setCurScene(game()->title());
    }
}
