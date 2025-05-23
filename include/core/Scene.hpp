#pragma once
#include <raylib.h>
#include "game/Tank.hpp"
#include "game/Bullet.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include <vector>

class Scene
{
public:
    Scene();
    ~Scene();
    void spawnBullet(b2Vec2 pos, float dir);
    void spawnTank(b2Vec2 pos, TankType type = TANK_PLAYER, TankColor color = TANK_GREEN);
    void update();
    void render();

private:
    b2WorldId m_worldId;
    std::vector<GameObject *> gameObjects;
    Texture2D backgroundTexture;
    b2ContactEvents m_contactEvents;
    b2ContactBeginTouchEvent* m_contactBeginTouchEvents;
};