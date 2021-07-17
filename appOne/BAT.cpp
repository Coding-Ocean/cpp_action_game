#include"window.h"
#include"ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BAT.h"
void BAT::create() {
    Chara = game()->container()->data().batChara;
    Bat = game()->container()->data().bat;
}
void BAT::appear(float wx , float wy, float vx, float vy) {
    Chara.hp = game()->container()->data().batChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Bat.triggerCnt = game()->container()->data().bat.triggerCnt;
}
void BAT::update() {
    //こうもり弾発射----------------------------------------------------------------
    Bat.elapsedTime += delta;
    if (Bat.elapsedTime >= Bat.interval) {
        Bat.elapsedTime -= Bat.interval;
        ++Bat.triggerCnt %= Bat.triggerInterval;
        if (Bat.triggerCnt == Bat.trigger1st ||
            Bat.triggerCnt == Bat.trigger2nd ||
            Bat.triggerCnt == Bat.trigger3rd ||
            Bat.triggerCnt == Bat.trigger4th ) {
            game()->characterManager()->appear(Bat.bulletCharaId,
                Chara.wx - Bat.bulletOffsetX, Chara.wy, -1, 0);
        }
    }
    //マップ------------------------------------------------------------------------
    // ウィンドウの外に出た
    if (Chara.wx < game()->map()->wDispLeft()) {
        Chara.hp = 0;
    }
    //ダメージを受けたときちょっとだけ透明化する------------------------------------
    if (Bat.damageTime > 0) {
        Bat.damageTime -= delta;
        Chara.color = Bat.damageColor;
    }
    else {
        Chara.color= Bat.normalColor;
    }
}
void BAT::damage() {
    if (Chara.hp > 0) {
        Bat.damageTime = Bat.damageInterval;
        Chara.hp--;
        if (Chara.hp == 0) {
            game()->characterManager()->appear(Bat.explosionCharaId, 
                Chara.wx, Chara.wy);
        }
    }
}
