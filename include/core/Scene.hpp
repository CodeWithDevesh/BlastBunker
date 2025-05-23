#pragma once
#include <raylib.h>
#include "game/Tank.hpp"
#include "game/Bullet.hpp"
#include "game/Explosion.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include <vector>

class Scene
{
public:
    Scene();
    ~Scene();
    static void spawnBullet(b2Vec2 pos, float dir);
    static void spawnTank(b2Vec2 pos, TankType type = TANK_PLAYER, TankColor color = TANK_GREEN);
    static void spawnExplosion(b2Vec2 pos);
    void update();
    void render();

private:
    b2WorldId m_worldId;
    static std::vector<GameObject *> gameObjects;
    Texture2D backgroundTexture;
    b2ContactEvents m_contactEvents;
    b2ContactBeginTouchEvent* m_contactBeginTouchEvents;
};