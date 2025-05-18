#pragma once
#include <raylib.h>
#include "Tank.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include <vector>

class Scene
{
public:
    Scene(TextureManager *, InputManager *);
    ~Scene();
    void spawnBullet(Vector2 pos, float dir);
    void spawnTank(Vector2 pos, TankType type = TANK_PLAYER, TankColor color = TANK_GREEN);
    void update();
    void render();

private:
    TextureManager *textureManager;
    InputManager *inputManager;
    std::vector<GameObject *> gameObjects;
};