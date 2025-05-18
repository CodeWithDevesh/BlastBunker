#pragma once

#include <raymath.h>

class Rectangle
{

    /*
    @param x: The x coordinate of center of the rectangle
    @param y: The y coordinate of center of the rectangle
    @param halfWidth: The width of the rectangle
    @param halfHeight: The height of the rectangle
    @param angle: The angle of the rectangle in radians
    */
    Rectangle(float x, float y, float halfWidth, float halfHeight, float angle = 0);
    ~Rectangle();

    bool CheckCollision(const Rectangle &other) const;
    void setAngle(float angle);
    void setPosition(float x, float y);

    inline Vector2 getPosition() const { return position; }
    inline float getAngle() const { return angle; }

    inline const Vector2 *getCorners() const { return corners; };

private:
    void updateCorners();

private:
    bool isColliding = false;
    Vector2 corners[4], localCorners[4];
    Vector2 position;
    float halfWidth;
    float halfHeight;
    float angle;
};