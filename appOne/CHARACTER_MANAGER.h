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
    class PLAYER* Player = nullptr;
public:
    CHARACTER_MANAGER(class GAME* game);
    ~CHARACTER_MANAGER();
    void create();
    void init();
    void appear(char charaId, float wx, float wy, float vx=0, float vy=0);
    void update();
    void draw();
    class PLAYER* player() { return Player; }
};
