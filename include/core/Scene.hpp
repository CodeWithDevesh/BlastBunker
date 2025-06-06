#pragma once
#include "game/Tank.hpp"
#include "game/Bullet.hpp"
#include "game/Explosion.hpp"
#include <vector>

#ifdef CLIENT
#include <raylib.h>
#include "AssetManager.hpp"
#include "InputManager.hpp"
#endif // CLIENT

class Scene
{
public:
    Scene();
    ~Scene();
    static void spawnBullet(b2Vec2 pos, float dir);
    static void spawnTank(b2Vec2 pos, TankType type = TANK_PLAYER, TankColor color = TANK_GREEN);
    static void spawnExplosion(b2Vec2 pos);
    void update();

#ifdef CLIENT
    void render();
#endif // CLIENT

private:
    b2WorldId m_worldId;
    static std::vector<GameObject *> gameObjects;
    b2ContactEvents m_contactEvents;
    b2ContactBeginTouchEvent *m_contactBeginTouchEvents;

#ifdef CLIENT
    Texture2D backgroundTexture;
#endif // CLIENT
};