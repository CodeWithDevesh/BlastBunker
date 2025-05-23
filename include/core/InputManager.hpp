#pragma once

#include <raylib.h>

class InputManager
{
private:
public:
    InputManager();
    ~InputManager();
    void Update();

    inline bool shouldMoveUp() const { return moveUp; };
    inline bool shouldMoveDown() const { return moveDown; };
    inline bool shouldMoveLeft() const { return moveLeft; };
    inline bool shouldMoveRight() const { return moveRight; };
    inline bool shouldFire() const { return fire; };
    inline bool shouldRotateLeft() const { return rotateLeft; };
    inline bool shouldRotateRight() const { return rotateRight; };

private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool fire = false;
    bool rotateLeft = false;
    bool rotateRight = false;
};
