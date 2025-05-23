#pragma once

#include "raylib.h"
#include "box2d/box2d.h"
#include "core/GameObject.hpp"
#include "raymath.h"


class Explosion :  public GameObject{
    public:
        Explosion (b2Vec2 pos);
        // void Update() override;
        // void Draw() override;
    private:
        Texture2D m_texture;
        int m_frameWidth, m_frameHeight;
        int m_currentFrame = 0;
        float m_time = 0;
        b2Vec2 m_position;
        float m_duration = 0.5f; // Duration of the explosion animation
        float m_scale = 1.0f; // Scale of the explosion
};