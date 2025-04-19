#include "GameObject.hpp"

void GameObject::Destroy()
{
    b2DestroyBody(m_body);
    isAlive = false;
}