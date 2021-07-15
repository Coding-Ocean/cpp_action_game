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
    game()->map()->update();
    game()->characterManager()->update();
}
void STAGE::draw(){
    clear(60,30,0);
    rectMode(CORNER);
    image(Stage.backImg, 0, 0);
    game()->map()->draw();
    game()->characterManager()->draw();
    game()->fade()->draw();
}
void STAGE::nextScene() {
    if (isTrigger(KEY_J)) {
        game()->fade()->outTrigger();
    }
    if (game()->fade()->outEndFlag()) {
        game()->setCurScene(game()->title());
    }
}
