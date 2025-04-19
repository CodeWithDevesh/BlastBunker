#include "Bullet.hpp"

Bullet::Bullet(b2WorldId world, b2Vec2 position, float radius, TextureManager* textureManager)
{
    m_bodyTexture = textureManager->getTexture(TEXTURE_BULLET);
    frameWidth = m_bodyTexture.width;
    frameHeight = m_bodyTexture.height;

    frameRec = {0, 0, (float)frameWidth, (float)frameHeight};

    // Define the body
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    m_body = b2CreateBody(world, &bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();
    // Define the shape
    shapeDef.density = 1.0f;


    m_shape = b2CreateCircleShape(m_body, &shapeDef, &circleShape);
}