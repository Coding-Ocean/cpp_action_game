#include"graphic.h"
#include"input.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "STAGE.h"
STAGE::STAGE(class GAME* game):
SCENE(game){
}
STAGE::~STAGE(){}
void STAGE::create(){
    Stage = game()->container()->data().stage;
}
void STAGE::init() {
}
void STAGE::update() {
}
void STAGE::draw(){
    clear();
    rectMode(CORNER);
    image(Stage.backImg, 0, 0);
}
void STAGE::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->setCurScene(game()->title());
    }
}
