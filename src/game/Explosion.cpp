#include "game/Explosion.hpp"
#include "core/Globals.hpp"

Explosion::Explosion(b2Vec2 pos)
{
    // m_texture = AssetManager::GetInstance()->getTexture(TEXTURE_EXPLOSION);
    m_texture = Globals::GetAssetManager()->getTexture(TEXTURE_EXPLOSION);
    m_frameWidth = m_texture.width / 4;
    m_frameHeight = m_texture.height / 4;
    m_position = pos;
}