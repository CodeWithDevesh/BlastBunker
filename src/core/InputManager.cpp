#include "core/InputManager.hpp"

InputManager::InputManager()
{
    // Constructor implementation
}
InputManager::~InputManager()
{
    // Destructor implementation
}

void InputManager::Update()
{
    // Update input state
    if (IsKeyDown(KEY_W))
        moveUp = true;
    else
        moveUp = false;
    if (IsKeyDown(KEY_S))
        moveDown = true;
    else
        moveDown = false;
    if (IsKeyDown(KEY_A))
        moveLeft = true;
    else
        moveLeft = false;
    if (IsKeyDown(KEY_D))
        moveRight = true;
    else
        moveRight = false;
    if (IsKeyPressed(KEY_SPACE))
        fire = true;
    else
        fire = false;
    if (IsKeyDown(KEY_LEFT))
        rotateLeft = true;
    else
        rotateLeft = false;
    if (IsKeyDown(KEY_RIGHT))
        rotateRight = true;
    else
        rotateRight = false;
}