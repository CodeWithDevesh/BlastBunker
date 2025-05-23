#pragma once

#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

#include "box2d/box2d.h"

enum GameObjectType
{
    GAME_OBJECT_TANK,
    GAME_OBJECT_BULLET,
};

class GameObject
{
public:
    bool isAlive = true;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void OnCollision(GameObject* other) {};
    virtual ~GameObject() {};
    void Destroy();

    GameObjectType objectType;

    b2BodyId m_bodyId;
    b2WorldId m_worldId;
    b2Vec2 bodyPos;
    float bodyAngle = 0;
    float scale = 1.0f;
protected:
};