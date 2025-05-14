#pragma once

#include "raylib.h"
#include "raymath.h"
#include "GameObject.hpp"
#include "TextureManager.hpp"

class Bullet : public GameObject
{
public:
    Bullet(Vector2 position, float rot, TextureManager *textureManager);
    ~Bullet();
    void Update() override;
    void Draw() override;

private:
    Texture2D m_bodyTexture;

    float frameWidth, frameHeight;
    Rectangle frameRec;
    float frameTime = 1.f / 12.f;
    float timer = 0.f;
    int currentFrame = 0;
    int frameCount = 2;

    Vector2 bodyPos;
    float bodyAngle = 0;

    float speed = 500.f;
    float scale = .3f;
};