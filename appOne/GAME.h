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
    class FADE* Fade = nullptr;
public:
    class TITLE* title() { return Title; }
    class STAGE* stage() { return Stage; }
    class FADE* fade() { return Fade; }
    void setCurScene(SCENE* scene);
//キャラクタ
private:
    class MAP* Map = nullptr;
    class CHARACTER_MANAGER* CharacterManager = nullptr;
public:
    class MAP* map() { return Map; }
    class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
//マネージャー
public:
    GAME();
    ~GAME();
    void run();
};