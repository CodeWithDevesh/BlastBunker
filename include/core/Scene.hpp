#pragma once
#include <raylib.h>
#include <box2d/box2d.h>
#include "GameObject.hpp"
#include <vector>

class Scene {
public:
  Scene();
  ~Scene();
  void addGameObject(GameObject *obj);
  void update();
  void render();

private:
  b2WorldId m_worldId;
  std::vector<GameObject *> gameObjects;
  Texture2D backgroundTexture;
  b2ContactEvents m_contactEvents;
  b2ContactBeginTouchEvent *m_contactBeginTouchEvents;
};
