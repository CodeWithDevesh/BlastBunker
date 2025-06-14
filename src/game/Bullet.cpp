#include "game/Bullet.hpp"
#include "core/Globals.hpp"

Bullet::Bullet(b2Vec2 position, float rot)
{
    m_bodyTexture = Globals::GetAssetManager()->getTexture(TEXTURE_BULLET);
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
    bodyDef.userData = this;
    // bodyDef.linearDamping = 1.5f;
    bodyDef.linearVelocity = {sinf(rot) * speed, cosf(rot) * speed};
    m_bodyId = b2CreateBody(Globals::GetWorldId(), &bodyDef);
    bodyCreated = true;

    b2Polygon box = b2MakeBox(frameWidth / 2, frameHeight / 2);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.enableContactEvents = true;
    b2CreatePolygonShape(m_bodyId, &shapeDef, &box);

    objectType = GAME_OBJECT_BULLET;

    m_playerFireSound = Globals::GetAssetManager()->getSound(SOUND_PLAYER_FIRE);
    PlaySound(m_playerFireSound);
}

Bullet::~Bullet()
{
    Destroy();
}

void Bullet::Update()
{
    if (!isAlive)
        return;

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
    if (!isAlive)
        return;

    DrawTexturePro(m_bodyTexture, frameRec, {bodyPos.x, bodyPos.y, (float)frameWidth, (float)frameHeight}, {(float)frameWidth / 2, (float)frameHeight / 2}, bodyAngle, WHITE);
}

void Bullet::OnCollision(GameObject *other)
{
    if(other == this)
        return;
    if (other->objectType == GAME_OBJECT_TANK)
    {
        printf("Bullet hit a tank\n");
    }else if (other->objectType == GAME_OBJECT_BULLET)
    {
        printf("Bullet hit another bullet\n");
    }else
    {
        printf("Bullet hit something else\n");
    }
    Destroy();
}