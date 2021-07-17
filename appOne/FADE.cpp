#include"graphic.h"
#include"window.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "FADE.h"
void FADE::create() {
    Fade = game()->container()->data().fade;
}
void FADE::inTrigger(){
    if( State == STATE::OUT_END ){
        State = STATE::IN_TRIGGER;
    }
}
void FADE::outTrigger(){
    if( State == STATE::IN_END ){
        State = STATE::OUT_TRIGGER;
    }
}
void FADE::draw(){
    if (State == STATE::IN_END ||
        State == STATE::OUT_END) {
        return;
    }
    rectMode(CORNER);
    colorMode(RGB,255);
    switch( State ){
    case STATE::IN_TRIGGER:
        Fade.color.a = 255;
        fill(Fade.color);
        rect(0, 0, width, height);
        State = STATE::IN_NOW;
        break;
    case STATE::IN_NOW:
        fill(Fade.color);
        rect(0, 0, width, height);
        Fade.color.a += -Fade.speed * delta;
        if( Fade.color.a < 0.0 ){
            Fade.color.a = 0.0f;
            State = STATE::IN_END;
        }
        break;
    case STATE::OUT_TRIGGER:
        Fade.color.a = 0.0f;
        State = STATE::OUT_NOW;
        break;
    case STATE::OUT_NOW:
        fill(Fade.color);
        rect(0, 0, width, height);
        Fade.color.a += Fade.speed * delta;
        if( Fade.color.a >= 255.0f ){
            Fade.color.a = 255.0f;
            State = STATE::OUT_END;
        }
        break;
    }
}
int FADE::inEndFlag(){
    return ( State == STATE::IN_END );
}
int FADE::outEndFlag(){
    return ( State == STATE::OUT_END );
}
void FADE::setColor(const COLOR& color){
    Fade.color = color;
}
void FADE::setSpeed( float speed ){
    Fade.speed = speed;
}
