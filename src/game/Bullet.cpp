#include "Bullet.hpp"

Bullet::Bullet(b2WorldId world, b2Vec2 position, b2Rot rot, TextureManager* textureManager)
{
    m_bodyTexture = textureManager->getTexture(TEXTURE_BULLET);
    frameWidth = m_bodyTexture.width;
    frameHeight = m_bodyTexture.height;

    frameRec = {0, 0, (float)frameWidth, (float)frameHeight};

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    bodyDef.rotation = rot;
    bodyDef.linearVelocity = {speed, 0};
    m_body = b2CreateBody(world, &bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    b2Polygon boxShape = b2MakeBox(frameWidth/2, frameHeight/2);
    m_shape = b2CreatePolygonShape(m_body, &shapeDef, &boxShape);
}

Bullet::~Bullet(){
    Destroy();
}

void Bullet::Update(){
    
}

void Bullet::Draw(){
    bodyPos.x = b2Body_GetPosition(m_body).x;
    bodyPos.y = screenHeight - b2Body_GetPosition(m_body).y;

    DrawTexturePro(m_bodyTexture, frameRec, {bodyPos.x, bodyPos.y, (float)frameWidth, (float)frameHeight}, {(float)frameWidth / 2, (float)frameHeight / 2}, b2Rot_GetAngle(b2Body_GetRotation(m_body)) * RAD2DEG, WHITE);
}