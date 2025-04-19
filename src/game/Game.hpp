#pragma once
#include <raylib.h>
#include <box2d/box2d.h>
#include "Tank.hpp"
#include "Constants.hpp"
#include "TextureManager.hpp"
#include <vector>

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

    b2WorldId m_b2WorldId;
    Tank *tank;

    float accumalator = 0;

    TextureManager *textureManager;
    std::vector<GameObject *> gameObjects;
};
