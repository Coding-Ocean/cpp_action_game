#pragma once
#include"TITLE.h"
class CONTAINER
{
private:
    struct DATA {
        TITLE::DATA title;
    };
    DATA Data;
public:
    void load();
    void setData();
    void loadGraphics();
    const DATA& data() { return Data; }
};

