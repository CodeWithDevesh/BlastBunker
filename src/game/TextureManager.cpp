#include "TextureManager.hpp"

TextureManager::TextureManager()
{
    for (int i = 0; i < 3; i++)
    {
        m_textures[i] = LoadTexture(m_texturePaths[i]);
    }
}
TextureManager::~TextureManager()
{
    for (int i = 0; i < 3; i++)
    {
        UnloadTexture(m_textures[i]);
    }
}
Texture2D TextureManager::getTexture(TextureType type)
{
    return m_textures[type];
}