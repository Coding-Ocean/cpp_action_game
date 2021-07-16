#include"graphic.h"
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
    Chara.wx = 0;
    Chara.hp = 0;
}
void CHARACTER::appear(float wx , float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = 1;
}
void CHARACTER::update() {
    if (Chara.wx - game()->map()->wx() < -game()->map()->chipSize()) {
        Chara.hp = 0;
    }
}
void CHARACTER::draw() {
    imageColor(Chara.color);
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    Chara.anims[Chara.animId]->draw(&Chara.imgIdx, &Chara.elapsedTime,
        px, py, Chara.angle, Chara.scale);
}
void CHARACTER::damage() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}