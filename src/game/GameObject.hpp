#pragma once

#include <box2d/box2d.h>
#include "raylib.h"
#include "raymath.h"
#include "Constants.hpp"

class GameObject
{
public:
    bool isAlive = true;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void OnCollision(GameObject* other) {};
    virtual ~GameObject() {};
    void Destroy();

protected:
    b2BodyId m_body;
    b2ShapeId m_shape;
};