#pragma once
#include <box2d/box2d.h>

enum GameObjectType {
  GAME_OBJECT_TANK,
  GAME_OBJECT_BULLET,
  GAME_OBJECT_EXPLOSION,
};

class GameObject {
public:
  bool isAlive = true;
  virtual void Update() = 0;
  virtual void Draw() = 0;
  virtual void OnCollision(GameObject *other) {};
  virtual ~GameObject() {};
  void Destroy();

  void setTransform(b2Vec2 pos, b2Rot rot);
  b2Rot getRotation();
  b2Vec2 getPosition();
  void setVelocity(b2Vec2 vel);

  GameObjectType objectType;

protected:
  b2BodyId m_bodyId;
  b2WorldId m_worldId;
  b2Vec2 bodyPos;
  float bodyAngle = 0;
  float scale = 1.0f;
  bool bodyCreated = false;
};
