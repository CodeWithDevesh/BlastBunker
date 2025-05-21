#include "Bullet.hpp"

Bullet::Bullet(b2WorldId worldId, b2Vec2 position, float rot, TextureManager *textureManager)
{
    m_bodyTexture = textureManager->getTexture(TEXTURE_BULLET);
    frameWidth = (float)m_bodyTexture.width;
    frameHeight = (float)m_bodyTexture.height;

    bodyPos = position;
    bodyAngle = rot;

    frameRec = {0, 0, (float)frameWidth, (float)frameHeight};

    frameWidth *= scale;
    frameHeight *= scale;

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.isBullet = true;
    bodyDef.position = {bodyPos.x, bodyPos.y};
    bodyDef.fixedRotation = true;
    bodyDef.rotation = b2MakeRot(rot);
    // bodyDef.linearDamping = 1.5f;
    bodyDef.linearVelocity = {sinf(rot) * speed, cosf(rot) * speed};
    m_bodyId = b2CreateBody(worldId, &bodyDef);

    b2Polygon box = b2MakeBox(frameWidth / 2, frameHeight / 2);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(m_bodyId, &shapeDef, &box);
}

Bullet::~Bullet()
{
    Destroy();
}

void Bullet::Update()
{
    bodyPos.x = b2Body_GetPosition(m_bodyId).x;
    bodyPos.y = screenHeight - b2Body_GetPosition(m_bodyId).y;
    bodyAngle = b2Rot_GetAngle(b2Body_GetRotation(m_bodyId)) * RAD2DEG;

    if (bodyPos.x < 0 || bodyPos.x > screenWidth || bodyPos.y < 0 || bodyPos.y > screenHeight)
    {
        Destroy();
    }
}

void Bullet::Draw()
{
    DrawTexturePro(m_bodyTexture, frameRec, {bodyPos.x, bodyPos.y, (float)frameWidth, (float)frameHeight}, {(float)frameWidth / 2, (float)frameHeight / 2}, bodyAngle, WHITE);
}