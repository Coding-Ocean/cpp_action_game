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
    class SCENE* CurScene = nullptr;
public:
    class TITLE* title() { return Title; }
//マネージャー
public:
    GAME();
    ~GAME();
    void run();
};