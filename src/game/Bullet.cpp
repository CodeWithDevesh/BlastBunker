#include "Bullet.hpp"

Bullet::Bullet(Vector2 position, float rot, TextureManager* textureManager)
{
    m_bodyTexture = textureManager->getTexture(TEXTURE_BULLET);
    frameWidth = (float) m_bodyTexture.width;
    frameHeight = (float) m_bodyTexture.height;

    bodyPos = position;
    bodyAngle = rot;

    frameRec = {0, 0, (float)frameWidth, (float)frameHeight};

    frameWidth *= scale;
    frameHeight *= scale;
}

Bullet::~Bullet(){
    Destroy();
}

void Bullet::Update(){
    bodyPos.x += sinf(bodyAngle) * speed * fixedTimeStep;
    bodyPos.y += -cosf(bodyAngle) * speed * fixedTimeStep;

    if(bodyPos.x < 0 || bodyPos.x > screenWidth || bodyPos.y < 0 || bodyPos.y > screenHeight){
        Destroy();
    }
}

void Bullet::Draw(){
    DrawTexturePro(m_bodyTexture, frameRec, {bodyPos.x, bodyPos.y, (float)frameWidth, (float)frameHeight}, {(float)frameWidth/ 2, (float)frameHeight/ 2}, bodyAngle * RAD2DEG, WHITE);
}