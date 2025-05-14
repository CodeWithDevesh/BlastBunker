#pragma once

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
};