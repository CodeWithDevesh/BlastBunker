#include "core/GameObject.hpp"
#include "box2d/box2d.h"

void GameObject::Destroy() {
  if (isAlive && bodyCreated)
    b2DestroyBody(m_bodyId);
  isAlive = false;
}

void GameObject::setTransform(b2Vec2 pos, b2Rot rot) {
  b2Body_SetTransform(m_bodyId, pos, rot);
}

b2Vec2 GameObject::getPosition() { return b2Body_GetPosition(m_bodyId); }
b2Rot GameObject::getRotation() { return b2Body_GetRotation(m_bodyId); }

void GameObject::setVelocity(b2Vec2 vel) {
  b2Body_SetLinearVelocity(m_bodyId, vel);
}
