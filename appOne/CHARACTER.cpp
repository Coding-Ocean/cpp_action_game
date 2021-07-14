#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"CHARACTER.h"
CHARACTER::CHARACTER(GAME* game):
    GAME_OBJECT(game){
}
CHARACTER::~CHARACTER(){
}
void CHARACTER::create() {
}
void CHARACTER::init() {
    Chara.hp = 0;
}
void CHARACTER::appear(const VECTOR2& world, const VECTOR2& vec) {
    Chara.world = world;
    Chara.hp = 1;
}
void CHARACTER::update() {
    if (Chara.world.x - game()->map()->world().x < -game()->map()->chipSize()) {
        Chara.hp = 0;
    }
}
void CHARACTER::draw() {
    VECTOR2 pos = Chara.world - game()->map()->world();
    Chara.anims[Chara.animId]->draw(&Chara.imgIdx, &Chara.elapsedTime, pos);
}
void CHARACTER::damage() {
}