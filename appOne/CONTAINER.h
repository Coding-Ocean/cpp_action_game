#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"FADE.h"
#include"MAP.h"
class CONTAINER
{
private:
    struct DATA {
        TITLE::DATA title;
        STAGE::DATA stage;
        FADE::DATA fade;
        MAP::DATA map;
    };
    DATA Data;
    void CreateData();
    void LoadGraphics();
public:
    void load();
    const DATA& data() { return Data; }
};

