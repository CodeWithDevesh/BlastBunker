#pragma once
#include <raylib.h>

class Tank
{
public:
    void Init(Vector2 startPosition);
    void Update();
    void Render();

private:
    Vector2 position;
    float rotation;
    float speed;
    Texture2D texture;
};
