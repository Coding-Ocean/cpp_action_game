#pragma once
#include"TITLE.h"
#include"STAGE.h"
class CONTAINER
{
private:
    struct DATA {
        TITLE::DATA title;
        STAGE::DATA stage;
    };
    DATA Data;
public:
    void load();
    void setData();
    void loadGraphics();
    const DATA& data() { return Data; }
};

