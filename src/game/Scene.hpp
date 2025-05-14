#pragma once
#include <raylib.h>
#include "box2d/box2d.h"
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "TextureManager.hpp"
#include <vector>

class Scene
{
public:
    Scene(TextureManager *, b2WorldId);
    ~Scene();
    void spawnBullet(b2Vec2 pos, b2Rot dir);
    void spawnTank(b2Vec2 pos);
    void update();
    void render();

private:
    TextureManager *textureManager;
    std::vector<GameObject *> gameObjects;
    b2WorldId world;
};