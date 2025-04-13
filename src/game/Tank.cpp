#include "Tank.hpp"

Tank::Tank(b2WorldId world, b2Vec2 position, float radius)
    : m_radius(radius)
{
    // Define the body
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    m_body = b2CreateBody(world, &bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();
    // Define the shape
    shapeDef.density = 1.0f;
    b2Circle circleShape;
    circleShape.radius = m_radius;
    circleShape.center.x = 0;
    circleShape.center.y = 0;
    m_shape = b2CreateCircleShape(m_body, &shapeDef, &circleShape);
}

void Tank::Update()
{
    b2Vec2 force;
    force.x = 0;
    force.y = 0;
    b2Vec2 vel;
    vel.x = 0;
    vel.y = 0;

    if (IsKeyDown(KEY_W))
        // force.y -= m_acceleration;
        vel.y = -maxVely;
    if (IsKeyDown(KEY_S))
        vel.y = maxVely;
    if (IsKeyDown(KEY_A))
        vel.x = -maxVelx;
    if (IsKeyDown(KEY_D))
        vel.x = maxVelx;

    // b2Body_ApplyLinearImpulseToCenter(m_body, force, true);

    b2Body_SetLinearVelocity(m_body, vel);

    // Get mouse movement delta
    float deltaX = GetMouseDelta().x;
    float deltaY = GetMouseDelta().y;

    // Update turret direction based on mouse movement
    turretX += deltaX * turretSensitivity;
    turretY += deltaY * turretSensitivity;

    // Normalize turret direction vector
    float mag = sqrt(turretX * turretX + turretY * turretY);
    if (mag > 0.0f)
    {
        turretX /= mag;
        turretY /= mag;
    }
}

void Tank::Draw()
{
    b2Vec2 pos = b2Body_GetPosition(m_body);
    DrawCircle((int)pos.x, (int)pos.y, m_radius, BLUE);
    float mouseX = GetMouseX();
    float mouseY = GetMouseY();

    // float mag = sqrt((turretX*turretX + turretY*turretY));
    Vector2 turretOffset = Vector2Scale({turretX, turretY}, 2 * m_radius);
    DrawLine(pos.x, pos.y, pos.x + turretOffset.x, pos.y + turretOffset.y, BLUE);
}
