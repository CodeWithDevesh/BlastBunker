#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height, float angle) : halfWidth(width), halfHeight(height), angle(angle)
{
    position.x = x;
    position.y = y;

    localCorners[0] = {-halfWidth, -halfHeight};
    localCorners[1] = {halfWidth, -halfHeight};
    localCorners[2] = {halfWidth, halfHeight};
    localCorners[3] = {-halfWidth, halfHeight};

    updateCorners();
}

Rectangle::~Rectangle()
{
    // Destructor implementation
}

void Rectangle::updateCorners()
{
    float cosA = cos(angle);
    float sinA = sin(angle);

    for (int i = 0; i < 4; i++)
    {
        float x = localCorners[i].x;
        float y = localCorners[i].y;

        corners[i].x = position.x + (x * cosA - y * sinA);
        corners[i].y = position.y + (x * sinA + y * cosA);
    }
}

void Rectangle::setAngle(float angle)
{
    this->angle = angle;
    updateCorners();
}

void Rectangle::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
    updateCorners();
}