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
        float centerX = 0;
        char bulletCharaId = 0;
        float bulletOffsetX = 0;
    };
    //プレイヤーの状態(奮闘中=プレイ中、死んだ、生き残った)
    enum STATE { STATE_STRUGGLING, STATE_DIED, STATE_SURVIVED };
private: 
    DATA Player;
    STATE State;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void appear(const VECTOR2& world, const VECTOR2& vec);
    void update();
    void damage();
    bool died();
    //{
    //    if (State == STATE_DIED) {
    //        Chara.vec.y += Player.gravity * delta;
    //        Chara.world.y += Chara.vec.y;
    //        draw();
    //        return true;
    //    }
    //    return false;
    //}
    bool survived() { return State == STATE_SURVIVED; }
};

