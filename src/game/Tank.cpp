#include "game/Tank.hpp"
#include "core/Game.hpp"
#include "core/Globals.hpp"
#include "core/Scene.hpp"

Tank::Tank(b2Vec2 pos, TankType type, TankColor color)
{
    m_inputManager = Globals::GetInputManager();

    bodyPos = pos;
    m_tankType = type;
    m_tankColor = color;

    if (type == TANK_ENEMY)
    {
        healthBarColor = RED;
    }

    m_bodyTexture = Globals::GetAssetManager()->getTexture(TEXTURE_TANK_GREEN_BODY);
    m_turretTexture = Globals::GetAssetManager()->getTexture(TEXTURE_TANK_GREEN_TURRET);
    m_playerFireSound = Globals::GetAssetManager()->getSound(SOUND_PLAYER_FIRE);

    bodyFrameWidth = m_bodyTexture.width / 2;
    bodyFrameHeight = m_bodyTexture.height;
    turretFrameWidth = m_turretTexture.width / 7;
    turretFrameHeight = m_turretTexture.height;

    bodyFrameRec = {0, 0, (float)bodyFrameWidth, (float)bodyFrameHeight};
    turretFrameRec = {0, 0, (float)turretFrameWidth, (float)turretFrameHeight};

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = {bodyPos.x, bodyPos.y};
    bodyDef.linearDamping = 2;
    bodyDef.angularDamping = 1;
    bodyDef.userData = this;
    m_bodyId = b2CreateBody(Globals::GetWorldId(), &bodyDef);
    bodyCreated = true;

    b2Polygon box = b2MakeBox(bodyFrameWidth / 2, bodyFrameHeight / 2);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.enableContactEvents = true;
    b2CreatePolygonShape(m_bodyId, &shapeDef, &box);

    objectType = GAME_OBJECT_TANK;
}

Tank::~Tank()
{
    Destroy();
}

void Tank::Update()
{
    if (!isAlive)
        return;

    b2Vec2 force = {0, 0};
    moving = false;
    if (m_tankType == TANK_PLAYER)
    {
        if (m_inputManager->shouldMoveUp())
        {
            force.y = 1;
            moving = true;
        }
        if (m_inputManager->shouldMoveDown())
        {
            force.y = -1;
            moving = true;
        }
        if (m_inputManager->shouldMoveLeft())
        {
            force.x = -1;
            moving = true;
        }
        if (m_inputManager->shouldMoveRight())
        {
            force.x = 1;
            moving = true;
        }
        force = b2MulSV(maxForce, b2Normalize(force));
        if (m_inputManager->shouldRotateLeft())
            turretAngle -= turretSensitivity;
        if (m_inputManager->shouldRotateRight())
            turretAngle += turretSensitivity;

        if (m_inputManager->shouldFire())
        {
            if (!firing)
            {
                fire();
                firing = true;
            }
        }
    }
    turretAngle = fmod(turretAngle, 360.0f);
    b2Body_ApplyLinearImpulseToCenter(m_bodyId, force, true);
    b2Vec2 vel = b2Body_GetLinearVelocity(m_bodyId);
    // vel = b2Mul(b2Normalize(vel), {maxVel, maxVel});
    if (moving)
    {
        float currentAngle = b2Rot_GetAngle(b2Body_GetRotation(m_bodyId));
        float targetAngle = atan2(vel.x, -vel.y);
        float angleDiff = shortestAngleDiff(targetAngle, currentAngle);
        float angleThreshold = 0.01f;

        if (fabsf(angleDiff) < angleThreshold)
        {
            b2Body_SetAngularVelocity(m_bodyId, 0);
        }
        else
        {
            float turnSpeed = 2.0f;
            b2Body_SetAngularVelocity(m_bodyId, angleDiff > 0 ? turnSpeed : -turnSpeed);
        }
    }

    b2Vec2 currentRightNormal = b2Body_GetWorldVector(m_bodyId, {1, 0}); // Right direction of tank
    b2Vec2 lateralVelocity = b2Dot(currentRightNormal, b2Body_GetLinearVelocity(m_bodyId)) * currentRightNormal;

    float driftControl = 0.2f;

    b2Vec2 impulse = -lateralVelocity * b2Body_GetMass(m_bodyId) * driftControl;
    b2Body_ApplyLinearImpulse(m_bodyId, impulse, b2Body_GetWorldCenterOfMass(m_bodyId), true);

    bodyPos = b2Body_GetPosition(m_bodyId);
    bodyPos.y = screenHeight - bodyPos.y;
    bodyAngle = -b2Rot_GetAngle(b2Body_GetRotation(m_bodyId)) * RAD2DEG;

    healthBarX = bodyPos.x - healthBarWidth / 2;
    healthBarY = bodyPos.y + bodyFrameHeight / 2 + turretFrameHeight / 2;
}

void Tank::Draw()
{
    if (!isAlive)
        return;

    updateAnimation();

    // Draw the body of tank
    DrawTexturePro(m_bodyTexture, bodyFrameRec, {bodyPos.x, bodyPos.y, (float)bodyFrameWidth, (float)bodyFrameHeight}, {(float)bodyFrameWidth / 2, (float)bodyFrameHeight / 2}, bodyAngle, WHITE);

    // Background of the health bar
    DrawRectangle(healthBarX, healthBarY, healthBarWidth, healthBarHeight, GRAY);
    // Foreground of the health bar (based on health percentage)
    float healthPercentage = (float)health / maxHealth;
    DrawRectangle(healthBarX, healthBarY, healthBarWidth * healthPercentage, healthBarHeight, healthBarColor);

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
    b2Vec2 p = b2Body_GetPosition(m_bodyId);
    p.x += sinf(turretAngle * DEG2RAD) * turretFrameHeight;
    p.y += cosf(turretAngle * DEG2RAD) * turretFrameHeight;
    Game::spwanBullet(p, turretAngle * DEG2RAD);

    b2Vec2 imp = {sinf((180 + turretAngle) * DEG2RAD), cosf((180 + turretAngle) * DEG2RAD)};
    imp = b2MulSV(recolingForce, b2Normalize(imp));

    b2Body_ApplyLinearImpulseToCenter(m_bodyId, imp, true);
}

void Tank::DrawDebug()
{
    b2Vec2 pos = b2Body_GetPosition(m_bodyId);
    float angle = b2Rot_GetAngle(b2Body_GetRotation(m_bodyId));

    // Draw the collision shape as a rectangle
    DrawRectanglePro(
        {pos.x, screenHeight - pos.y, (float)bodyFrameWidth, (float)bodyFrameHeight},
        {(float)bodyFrameWidth / 2, (float)bodyFrameHeight / 2},
        -bodyAngle,
        BLUE);
    DrawRectanglePro(
        {pos.x, pos.y, (float)bodyFrameWidth, (float)bodyFrameHeight},
        {(float)bodyFrameWidth / 2, (float)bodyFrameHeight / 2},
        bodyAngle,
        RED);
}

float Tank::shortestAngleDiff(float a, float b)
{
    float diff = fmodf(a - b + B2_PI, 2.0f * B2_PI);
    if (diff < 0)
        diff += 2.0f * B2_PI;
    return diff - B2_PI;
}

void Tank::OnCollision(GameObject *other)
{
    if (other == this)
        return;
    if (other->objectType == GAME_OBJECT_BULLET)
    {
        printf("Tank collided with bullet\n");
        health--;
        if (health <= 0)
        {
            Scene::spawnExplosion(b2Body_GetPosition(m_bodyId));
            Destroy();
        }
    }
    else
    {
        printf("Tank collided with %d\n", other->objectType);
    }
}