#pragma once

#include "core/GameObject.hpp"
#include "raylib.h"

class Explosion : public GameObject {
public:
  Explosion(b2Vec2 pos);
  void Update() override;
  void Draw() override;

private:
  Texture2D m_texture;
  Sound m_sound;
  float m_frameWidth, m_frameHeight;
  int m_currentFrame = 0;
  b2Vec2 m_position;
  int frameCount = 25;
  float m_timePerFrame = 1.0f / 60;
  float m_scale = 1.0f;

  Rectangle m_src, m_dest;
  float m_timer = 0.0f;
};
