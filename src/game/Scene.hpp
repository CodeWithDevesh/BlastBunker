#pragma once
#include <raylib.h>
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "TextureManager.hpp"
#include <vector>

class Scene
{
public:
    Scene(TextureManager *);
    ~Scene();
    void spawnBullet(Vector2 pos, float dir);
    void spawnTank(Vector2 pos);
    void update();
    void render();

private:
    TextureManager *textureManager;
    std::vector<GameObject *> gameObjects;
};