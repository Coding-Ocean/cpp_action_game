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
public:
    class TITLE* title() { return Title; }
    class STAGE* stage() { return Stage; }
    void setCurScene(SCENE* scene) { CurScene = scene; }
//�}�l�[�W���[
public:
    GAME();
    ~GAME();
    void run();
};