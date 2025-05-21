#include "AssetManager.hpp"

AssetManager::AssetManager()
{
    for (int i = 0; i < TEXTURE_COUNT; i++)
    {
        m_textures[i] = LoadTexture(m_texturePaths[i]);
    }

    for (int i = 0; i < SOUND_COUNT; i++)
    {
        m_sounds[i] = LoadSound(m_soundPaths[i]);
    }
}
AssetManager::~AssetManager()
{
    for (int i = 0; i < TEXTURE_COUNT; i++)
    {
        UnloadTexture(m_textures[i]);
    }

    for (int i = 0; i < SOUND_COUNT; i++)
    {
        UnloadSound(m_sounds[i]);
    }
}
Texture2D AssetManager::getTexture(TextureType type)
{
    return m_textures[type];
}

Sound AssetManager::getSound(SoundType type)
{
    return m_sounds[type];
}