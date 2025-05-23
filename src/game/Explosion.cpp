#include "game/Explosion.hpp"
#include "core/Globals.hpp"

Explosion::Explosion(b2Vec2 pos)
{
    // m_texture = AssetManager::GetInstance()->getTexture(TEXTURE_EXPLOSION);
    m_texture = Globals::GetAssetManager()->getTexture(TEXTURE_EXPLOSION);
    m_sound = Globals::GetAssetManager()->getSound(SOUND_EXPLOSION);
    m_frameWidth = m_texture.width / 5;
    m_frameHeight = m_texture.height / 5;
    m_position = pos;
    m_position.y = screenHeight - m_position.y;

    m_dest = {m_position.x, m_position.y, m_frameWidth * m_scale, m_frameHeight * m_scale};
    m_src = {0, 0, (float)m_frameWidth, (float)m_frameHeight};

    PlaySound(m_sound);
}

void Explosion::Update()
{
    if (!isAlive)
        return;
    if (m_timer > m_timePerFrame)
    {
        m_timer = 0.0f;
        m_currentFrame++;
        if (m_currentFrame >= frameCount)
        {
            Destroy();
            return;
        }

        m_src.x = (m_currentFrame % 5) * m_frameWidth;
        m_src.y = (m_currentFrame / 5) * m_frameHeight;
    }
    else
    {
        m_timer += fixedTimeStep;
    }
}

void Explosion::Draw()
{
    if (!isAlive)
        return;
    DrawTexturePro(m_texture, m_src, m_dest, {m_frameWidth * scale / 2, m_frameHeight * scale / 2}, 0.0f, WHITE);
}
