#pragma once
#include <raylib.h>
#include <box2d/box2d.h>
#include "Tank.hpp"
#include "Constants.hpp"
#include <iostream>

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
    
    b2WorldId m_b2WorldId;
    Tank *tank;

    float accumalator = 0;
};
