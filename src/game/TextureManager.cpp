#include "TextureManager.hpp"

TextureManager::TextureManager()
{
    int n = sizeof(m_textures) / sizeof(m_textures[0]);
    for (int i = 0; i < n; i++)
    {
        m_textures[i] = LoadTexture(m_texturePaths[i]);
    }
}
TextureManager::~TextureManager()
{
    int n = sizeof(m_textures) / sizeof(m_textures[0]);
    for (int i = 0; i < n; i++)
    {
        UnloadTexture(m_textures[i]);
    }
}
Texture2D TextureManager::getTexture(TextureType type)
{
    return m_textures[type];
}