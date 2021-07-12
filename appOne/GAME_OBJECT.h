#pragma once
class GAME_OBJECT
{
private:
    class GAME* Game = nullptr;
public:
    GAME_OBJECT(class GAME* game);
    ~GAME_OBJECT();
    class GAME* game() { return Game; }
};

