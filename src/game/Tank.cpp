#include "Tank.hpp"
#include "Game.hpp"

Tank::Tank(Vector2 pos, TextureManager *textureManager)
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
}

void Tank::Update()
{
    Vector2 vel;
    vel.x = 0;
    vel.y = 0;

    if (IsKeyDown(KEY_W))
        // force.y -= acc;
        vel.y = -1;
    if (IsKeyDown(KEY_S))
        vel.y = 1;
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

    vel = Vector2Multiply(Vector2Normalize(vel), {maxVel, maxVel});
    if (fabs(vel.x) > 0.01f || fabs(vel.y) > 0.01f)
    {
        moving = true;
        bodyAngle = atan2(vel.x, -vel.y); // Radians!
        bodyPos.x += vel.x * fixedTimeStep;
        bodyPos.y += vel.y * fixedTimeStep;
    }
    else
        moving = false;
}

void Tank::Draw()
{
    updateAnimation();

    // Draw the body of tank
    DrawTexturePro(m_bodyTexture, bodyFrameRec, {bodyPos.x, bodyPos.y, (float)bodyFrameWidth, (float)bodyFrameHeight}, {(float)bodyFrameWidth / 2, (float)bodyFrameHeight / 2}, bodyAngle * RAD2DEG, WHITE);

    // Draw the turret
    DrawTexturePro(m_turretTexture, turretFrameRec, {bodyPos.x, bodyPos.y, (float)turretFrameWidth, (float)turretFrameHeight}, {(float)turretFrameWidth / 2, (float)turretFrameHeight - turretOffset}, turretAngle, WHITE);
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
    Vector2 p = bodyPos;
    p.x += sinf(turretAngle * DEG2RAD) * turretFrameHeight / 1.2;
    p.y += -cosf(turretAngle * DEG2RAD) * turretFrameHeight / 1.2;
    Game::spwanBullet(p, turretAngle * DEG2RAD);
}