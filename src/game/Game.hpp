#pragma once
#include <raylib.h>
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
    static void spwanBullet(Vector2 pos, float dir);

private:
    void Update();
    void Render();

    static Scene* scene;

    float accumalator = 0;

    TextureManager *textureManager;
};
