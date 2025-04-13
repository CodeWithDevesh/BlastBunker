#pragma once
#include <box2d/box2d.h>
#include "raylib.h"

class Tank {
public:
    Tank(b2WorldId world, b2Vec2 position, float radius);
    void Update();
    void Draw();

private:
    b2BodyId m_body;
    b2ShapeId m_shape;
    float m_radius;
    float m_acceleration = 10000.0f;
    float maxVelx = 200;
    float maxVely = 200;
};
