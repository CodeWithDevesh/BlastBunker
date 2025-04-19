#pragma once
#include <box2d/box2d.h>
#include "raylib.h"
#include "raymath.h"
#include "TextureManager.hpp"
#include "iostream"
#include "Constants.hpp"
#include "GameObject.hpp"

class Tank : public GameObject
{
public:
    Tank(b2WorldId world, b2Vec2 position, TextureManager *textureManager);
    void Update() override;
    void Draw() override;

private:
    void updateAnimation();
    void fire();

    float acc = 10000.0f;
    float maxVel = 200.f;

    float turretSensitivity = 5;
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

    Vector2 bodyPos;

    bool moving = false;
};
