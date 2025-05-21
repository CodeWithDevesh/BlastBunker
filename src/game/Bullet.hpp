#pragma once

#include "raylib.h"
#include "raymath.h"
#include "GameObject.hpp"
#include "TextureManager.hpp"

class Bullet : public GameObject
{
public:
    Bullet(b2WorldId worldId, b2Vec2 position, float rot, TextureManager *textureManager);
    ~Bullet();
    void Update() override;
    void Draw() override;

private:
    Texture2D m_bodyTexture;

    float frameWidth, frameHeight;
    Rectangle frameRec;

    float speed = 1000.f;
    float scale = .3f;
};