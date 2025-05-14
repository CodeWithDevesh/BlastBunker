#include "Tank.hpp"
#include "Game.hpp"

Tank::Tank(b2WorldId world, b2Vec2 position, TextureManager *textureManager)
{
    // set the textures
    m_bodyTexture = textureManager->getTexture(TEXTURE_TANK_GREEN_BODY);
    m_turretTexture = textureManager->getTexture(TEXTURE_TANK_GREEN_TURRET);
    bodyFrameWidth = m_bodyTexture.width / 2;
    bodyFrameHeight = m_bodyTexture.height;
    turretFrameWidth = m_turretTexture.width / 7;
    turretFrameHeight = m_turretTexture.height;

    bodyFrameRec = {0, 0, (float)bodyFrameWidth, (float)bodyFrameHeight};
    turretFrameRec = {0, 0, (float)turretFrameWidth, (float)turretFrameHeight};

    // Define the body
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    m_body = b2CreateBody(world, &bodyDef);

    // Define the shape
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    b2Polygon boxShape = b2MakeBox(bodyFrameWidth / 2, bodyFrameHeight / 2);
    m_shape = b2CreatePolygonShape(m_body, &shapeDef, &boxShape);
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
        // force.y -= acc;
        vel.y = 1;
    if (IsKeyDown(KEY_S))
        vel.y = -1;
    if (IsKeyDown(KEY_A))
        vel.x = -1;
    if (IsKeyDown(KEY_D))
        vel.x = 1;

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_N))
        turretAngle -= turretSensitivity;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_M))
        turretAngle += turretSensitivity;

    if (IsKeyDown(KEY_SPACE))
    {
        if (!firing)
        {
            fire();
            firing = true;
        }
    }
    turretAngle = fmod(turretAngle, 360.0f);

    // b2Body_ApplyLinearImpulseToCenter(m_body, force, true);

    vel = b2Mul(b2Normalize(vel), {maxVel, maxVel});
    if (vel.x || vel.y)
        moving = true;
    else
        moving = false;

    b2Body_SetLinearVelocity(m_body, vel);

    // vel = b2Body_GetLinearVelocity
    if (fabs(vel.x) > 0.01f || fabs(vel.y) > 0.01f) // Avoid flickering at zero
    {
        float angle = atan2(vel.x, vel.y); // Radians!
        b2Body_SetTransform(m_body, b2Body_GetPosition(m_body), b2MakeRot(angle));
    }

    // Get mouse movement delta
    // float deltaX = GetMouseDelta().x;
    // float deltaY = GetMouseDelta().y;

    // Update turret direction based on mouse movement
    // turretX += deltaX * turretSensitivity;
    // turretY += deltaY * turretSensitivity;

    // // Normalize turret direction vector
    // float mag = sqrt(turretX * turretX + turretY * turretY);
    // if (mag > 0.0f)
    // {
    //     turretX /= mag;
    //     turretY /= mag;
    // }
}

void Tank::Draw()
{
    updateAnimation();

    bodyPos.x = b2Body_GetPosition(m_body).x;
    bodyPos.y = screenHeight - b2Body_GetPosition(m_body).y;

    // Draw the body of tank
    DrawTexturePro(m_bodyTexture, bodyFrameRec, {bodyPos.x, bodyPos.y, (float)bodyFrameWidth, (float)bodyFrameHeight}, {(float)bodyFrameWidth / 2, (float)bodyFrameHeight / 2}, b2Rot_GetAngle(b2Body_GetRotation(m_body)) * RAD2DEG, WHITE);

    // Draw the turret
    DrawTexturePro(m_turretTexture, turretFrameRec, {bodyPos.x, bodyPos.y, (float)turretFrameWidth, (float)turretFrameHeight}, {(float)turretFrameWidth / 2, (float)turretFrameHeight - turretOffset}, b2Rot_GetAngle(b2Body_GetRotation(m_body)) * RAD2DEG + turretAngle, WHITE);

    // DrawRectangleLines(pos.x, pos.y, 102, 138, WHITE);

    // float mag = sqrt((turretX*turretX + turretY*turretY));
    // Vector2 turretOffset = Vector2Scale({turretX, turretY}, 2 * m_radius);
    // DrawLine(pos.x, pos.y, pos.x + turretOffset.x, pos.y + turretOffset.y, BLUE);
}

void Tank::updateAnimation()
{

    if (moving)
        bodyTimer += GetFrameTime();
    if (bodyTimer >= bodyFrameTime)
    {
        bodyTimer = 0.0f;
        currentBodyFrame = (currentBodyFrame + 1) % bodyFrameCount;
    }

    if (firing)
        turretTimer += GetFrameTime();
    if (turretTimer >= turretFrameTime)
    {
        turretTimer = 0.0f;
        currentTurretFrame = (currentTurretFrame + 1) % turretFrameCount;
        if (currentTurretFrame == 0)
        {
            firing = false;
        }
    }

    bodyFrameRec.x = currentBodyFrame * bodyFrameWidth;
    turretFrameRec.x = currentTurretFrame * turretFrameWidth;
}

void Tank::fire()
{
    b2Vec2 pos = b2Body_GetPosition(m_body);
    Game::spwanBullet(pos, b2MakeRot(b2Rot_GetAngle(b2Body_GetRotation(m_body)) + turretAngle / DEG2RAD));
}