#pragma once

#include <box2d/box2d.h>
#include "raylib.h"
#include "raymath.h"
#include "GameObject.hpp"
#include "TextureManager.hpp"

class Bullet : public GameObject
{
public:
    Bullet(b2WorldId world, b2Vec2 position, b2Rot rot, TextureManager *textureManager);
    ~Bullet();
    void Update() override;
    void Draw() override;

private:
    Texture2D m_bodyTexture;

    int frameWidth, frameHeight;
    Rectangle frameRec;
    float frameTime = 1.f / 12.f;
    float timer = 0.f;
    int currentFrame = 0;
    int frameCount = 2;

    Vector2 bodyPos;

    float speed = 100.f;
};