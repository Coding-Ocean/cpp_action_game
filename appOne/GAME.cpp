#include"framework.h"
#include"graphic.h"
#include"GAME.h"
GAME::GAME() {
}
GAME::~GAME() {
}
void GAME::run() {
    window(800, 600, full);
    while (notQuit) {
        clear();
        rect(0, 0, 800, 600);
    }
}
