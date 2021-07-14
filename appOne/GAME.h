#pragma once
class GAME {
//�R���e�i
private:
    class CONTAINER* Container = nullptr;
public:
    class CONTAINER* container() { return Container; };
//�V�[��
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
//�L�����N�^
private:
    class MAP* Map = nullptr;
    class CHARACTER_MANAGER* CharacterManager = nullptr;
public:
    class MAP* map() { return Map; }
    class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
//�}�l�[�W���[
public:
    GAME();
    ~GAME();
    void run();
};