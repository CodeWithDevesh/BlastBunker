#pragma once

#include "raylib.h"
#include "raymath.h"
#include "core/GameObject.hpp"
#include "core/AssetManager.hpp"

class Bullet : public GameObject
{
public:
    Bullet(b2Vec2 position, float rot);
    ~Bullet();
    void Update() override;
    void Draw() override;
    void OnCollision(GameObject *other) override;


private:
    Texture2D m_bodyTexture;

    float frameWidth, frameHeight;
    Rectangle frameRec;

    Sound m_playerFireSound;

    float speed = 1000.f;
    float scale = .3f;
};