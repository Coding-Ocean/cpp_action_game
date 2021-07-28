#include"graphic.h"
#include"ANIMS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"CHARACTER.h"
CHARACTER::CHARACTER(GAME* game):
    GAME_OBJECT(game){
}
void CHARACTER::create() {
}
void CHARACTER::init() {
    Chara.hp = 0;
}
void CHARACTER::appear(float wx , float wy, float vx, float vy) {
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.hp = 1;
}
void CHARACTER::update() {
    float px = Chara.wx - game()->map()->wx();
    if ( px < -game()->map()->chipSize()) {
        Chara.hp = 0;
    }
}
void CHARACTER::draw() {
    imageColor(Chara.color);
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    if (Chara.anims) {
        Chara.anims->anim(Chara.animId)->draw(&Chara.animData,
            px, py, Chara.angle, Chara.scale);
    }
    else if (Chara.anim) {
        Chara.anim->draw(&Chara.animData,
            px, py, Chara.angle, Chara.scale);
    }
    else{
        image(Chara.img, px, py, Chara.angle, Chara.scale);
    }
}
void CHARACTER::damage() {
    if (Chara.hp > 0) {
        Chara.hp--;
    }
}