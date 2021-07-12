#pragma once
class GAME {
//コンテナ
private:
    class CONTAINER* Container = nullptr;
public:
    class CONTAINER* container() { return Container; };
//シーン
private:
    class TITLE* Title = nullptr;
    class STAGE* Stage = nullptr;
    class SCENE* CurScene = nullptr;
public:
    class TITLE* title() { return Title; }
    class STAGE* stage() { return Stage; }
    void setCurScene(SCENE* scene) { CurScene = scene; }
//マネージャー
public:
    GAME();
    ~GAME();
    void run();
};