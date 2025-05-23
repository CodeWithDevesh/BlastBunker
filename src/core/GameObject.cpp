#include "core/GameObject.hpp"

void GameObject::Destroy()
{
    if (isAlive && bodyCreated)
        b2DestroyBody(m_bodyId);
    isAlive = false;
}
