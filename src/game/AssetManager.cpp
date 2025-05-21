#include "AssetManager.hpp"

AssetManager::AssetManager()
{
    int n = sizeof(m_textures) / sizeof(m_textures[0]);
    for (int i = 0; i < n; i++)
    {
        m_textures[i] = LoadTexture(m_texturePaths[i]);
    }
}
AssetManager::~AssetManager()
{
    int n = sizeof(m_textures) / sizeof(m_textures[0]);
    for (int i = 0; i < n; i++)
    {
        UnloadTexture(m_textures[i]);
    }
}
Texture2D AssetManager::getTexture(TextureType type)
{
    return m_textures[type];
}