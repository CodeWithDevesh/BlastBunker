#pragma once
#include "raylib.h"
#include "raymath.h"
#include "TextureManager.hpp"
#include "iostream"
#include "Constants.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"

#include "box2d/box2d.h"

class Game;

enum TankType
{
    TANK_PLAYER,
    TANK_ENEMY,
};
enum TankColor
{
    TANK_GREEN,
    TANK_RED,
    TANK_BLUE,
    TANK_YELLOW,
};

class Tank : public GameObject
{
public:
    Tank(b2WorldId worldId, b2Vec2 position, TextureManager *textureManager, InputManager *inputManager, TankType type = TANK_PLAYER, TankColor color = TANK_GREEN);
    ~Tank();
    void Update() override;
    void Draw() override;
    void OnCollision(GameObject *other) override;

    int health = 5;
    
    private:
    InputManager *m_inputManager;
    
    TankType m_tankType = TANK_PLAYER;
    TankColor m_tankColor = TANK_GREEN;
    
    void updateAnimation();
    void fire();
    float shortestAngleDiff(float a, float b);
    void DrawDebug();
    
    float maxForce = 12000.0f;
    float maxVel = 200.f;
    float recolingForce = 50000.f;
    
    float turretSensitivity = 2;
    float turretAngle = 0;
    float turretOffset = 8.f;
    
    Texture2D m_bodyTexture;
    Texture2D m_turretTexture;
    
    int bodyFrameWidth, bodyFrameHeight;
    Rectangle bodyFrameRec;
    float bodyFrameTime = 1.f / 12.f;
    float bodyTimer = 0.f;
    int currentBodyFrame = 0;
    int bodyFrameCount = 2;
    
    int turretFrameWidth, turretFrameHeight;
    Rectangle turretFrameRec;
    float turretFrameTime = 1.f / 42.f;
    float turretTimer = 0.f;
    int currentTurretFrame = 0;
    int turretFrameCount = 7;
    
    bool firing = false;
    bool moving = false;

    // Health
    int maxHealth = 5;
    float healthBarWidth = 50.0f;
    float healthBarHeight = 5.0f;
    float healthBarX = 0;
    float healthBarY = 0;
    Color healthBarColor = GREEN;
};
