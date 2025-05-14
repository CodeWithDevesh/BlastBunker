#pragma once
#include <raylib.h>
#include <box2d/box2d.h>
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "TextureManager.hpp"
#include <vector>
#include "Scene.hpp"

class Game
{
private:
public:
    Game(/* args */);
    void run();
    ~Game();
    static void spwanBullet(b2Vec2 pos, b2Rot dir);

private:
    void Update();
    void Render();

    b2WorldId m_b2WorldId;
    static Scene* scene;

    float accumalator = 0;

    TextureManager *textureManager;
};
