#pragma once
#include "GAME_OBJECT.h"
class CHARACTER_MANAGER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int numPlayers=0;
        int numPlayerBullets=0;
        int numPumpkins = 0;
        int numBats = 0;
        int numBatBullets = 0;
        int numExplosions = 0;
    };
private:
    int Total=0;
    DATA CharaMng;
    class CHARACTER** Characters = nullptr;
public:
    CHARACTER_MANAGER(class GAME* game);
    ~CHARACTER_MANAGER();
    void create();
    void init();
    void appear(char charaId, const VECTOR2& world, const VECTOR2& vec);
    void update();
    void draw();
};
