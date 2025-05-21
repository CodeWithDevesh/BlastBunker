#pragma once
#include <raylib.h>
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "TextureManager.hpp"
#include <vector>
#include "Scene.hpp"
#include "InputManager.hpp"

#include "box2d/box2d.h"

class Game
{
private:
public:
    Game(/* args */);
    void run();
    ~Game();
    static void spwanBullet(b2Vec2 pos, float dir);

private:
    void Update();
    void Render();

    static Scene* scene;

    float accumalator = 0;

    TextureManager *textureManager;
    InputManager *inputManager;
    b2WorldId m_worldId;
};
