#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"PUMPKIN.h"
#include"BAT.h"
#include"BAT_BULLET.h"
#include"EXPLOSION.h"
#include"CHARACTER_MANAGER.h"
CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game) :
    GAME_OBJECT(game) {
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
    for (int i = 0; i < Total; i++) {
        delete Characters[i];
    }
    delete[] Characters;
}
void CHARACTER_MANAGER::create() {
    CharaMng = game()->container()->data().charaMng;
    
    Total = 0;
    Total += CharaMng.numPlayers;
    Total += CharaMng.numPlayerBullets;
    Total += CharaMng.numPumpkins;
    Total += CharaMng.numBats;
    Total += CharaMng.numBatBullets;
    Total += CharaMng.numExplosions;
    Characters = new CHARACTER * [Total];

    int i, j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)       Characters[j++] = new PLAYER(game());
    for (i = 0; i < CharaMng.numPlayerBullets; i++) Characters[j++] = new PLAYER_BULLET(game());
    for (i = 0; i < CharaMng.numPumpkins; i++)      Characters[j++] = new PUMPKIN(game());
    for (i = 0; i < CharaMng.numBats; i++)          Characters[j++] = new BAT(game());
    for (i = 0; i < CharaMng.numBatBullets; i++)    Characters[j++] = new BAT_BULLET(game());
    for (i = 0; i < CharaMng.numExplosions; i++)    Characters[j++] = new EXPLOSION(game());

    for (int i = 0; i < Total; i++) {
        Characters[i]->create();
    }
}
void CHARACTER_MANAGER::init() {
    for (int i = 0; i < Total; i++) {
        Characters[i]->init();
    }
}
void CHARACTER_MANAGER::appear(char charaId, const VECTOR2& world, const VECTOR2& vec){
    // charaIdÇ≈éwíËÇ≥ÇÍÇΩÉLÉÉÉâÇèoåªÇ≥ÇπÇÈ
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->charaId() == charaId) {
            if (Characters[i]->hp() <= 0) {
                Characters[i]->appear(world, vec);
                break;
            }
        }
    }
}
void CHARACTER_MANAGER::update() {
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->update();
        }
    }
}
void CHARACTER_MANAGER::draw() {
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->draw();
        }
    }
}
