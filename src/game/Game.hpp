#pragma once
#include <raylib.h>
class Game
{
private:
public:
    Game(/* args */);
    void run();
    ~Game();

private:
    void Update();
    void Render();

    const int screenWidth = 800;
    const int screenHeight = 450;
};
