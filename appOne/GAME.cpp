#include"framework.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME.h"
GAME::GAME() {
    Container = new CONTAINER();
    Title = new TITLE(this);
    Stage = new STAGE(this);
}
GAME::~GAME() {
    delete Stage;
    delete Title;
    delete Container;
}
void GAME::run() {
    window(800, 600, full);
    Container->load();
    Title->create();
    Stage->create();
    CurScene = Title;
    while (notQuit) {
        CurScene->proc();
    }
}
