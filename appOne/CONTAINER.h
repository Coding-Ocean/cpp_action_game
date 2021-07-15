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
        CHARACTER::DATA playerChara;
        CHARACTER::DATA playerBulletChara;
        CHARACTER::DATA pumpkinChara;
        CHARACTER::DATA batChara;
        BAT::DATA bat;
        CHARACTER::DATA batBulletChara;
        CHARACTER::DATA explosionChara;
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

