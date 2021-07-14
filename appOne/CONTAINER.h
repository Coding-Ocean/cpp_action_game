#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"FADE.h"
#include"MAP.h"
#include"BAT.h"
#include"CHARACTER_MANAGER.h"
class CONTAINER
{
private:
    struct DATA {
        TITLE::DATA title;
        STAGE::DATA stage;
        FADE::DATA fade;
        MAP::DATA map;
        CHARACTER::DATA player;
        CHARACTER::DATA playerBullet;
        CHARACTER::DATA pumpkin;
        CHARACTER::DATA batChara;
        BAT::DATA bat;
        CHARACTER::DATA batBullet;
        CHARACTER::DATA explosion;
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

