#include "core/GameObject.hpp"

void GameObject::Destroy()
{
    if (isAlive)
        b2DestroyBody(m_bodyId);
    isAlive = false;
}
