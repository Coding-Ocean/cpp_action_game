#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int jumpFlag = 0;
        float initVecUp = 0;
        float initVecDown = 0;
        float gravity = 0;
        char bulletCharaId = 0;
        float bulletOffsetX = 0;
    };
    //プレイヤーの状態(奮闘中=プレイ中、死んだ、生き残った)
    enum STATE { STATE_STRUGGLING, STATE_DIED, STATE_FALL,STATE_SURVIVED };
private: 
    DATA Player;
    STATE State;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void appear(float wx , float wy, float vx, float vy);
    void update();
    void damage();
    bool died();
    bool survived() { return State == STATE_SURVIVED; }
    float wx() { return Chara.wx; }
};

