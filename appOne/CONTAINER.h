#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"FADE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"BAT.h"
#include"EXPLOSION.h"
#include"PUMPKIN.h"
#include"CHARACTER_MANAGER.h"
class CONTAINER
{
private:
    struct DATA {
        STAGE::DATA stage;
        FADE::DATA fade;
        MAP::DATA map;
        CHARACTER::DATA playerChara;
        PLAYER::DATA player;
        CHARACTER::DATA playerBulletChara;
        CHARACTER::DATA pumpkinChara;
        PUMPKIN::DATA pumpkin;
        CHARACTER::DATA batChara;
        BAT::DATA bat;
        CHARACTER::DATA batBulletChara;
        CHARACTER::DATA explosionChara;
        EXPLOSION::DATA explosion;
        CHARACTER_MANAGER::DATA charaMng;
    };
    DATA Data;
    void CreateData();
    void LoadGraphics();
public:
    ~CONTAINER();
    void load();
    const DATA& data() { return Data; }
};

