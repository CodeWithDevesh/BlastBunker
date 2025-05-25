#include "core/AssetManager.hpp"

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

    for (int i = 0; i < FIRE_SOUND_COUNT; i++)
    {
        bulletSounds[i] = LoadSound(m_soundPaths[SOUND_PLAYER_FIRE]);
        SetSoundVolume(bulletSounds[i], 0.5f);
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

    for (int i = 0; i < FIRE_SOUND_COUNT; i++)
    {
        UnloadSound(bulletSounds[i]);
    }
}
Texture2D AssetManager::getTexture(TextureType type)
{
    return m_textures[type];
}

Sound AssetManager::getSound(SoundType type)
{
    if (type == SOUND_PLAYER_FIRE)
    {
        currentFirePlayerSound = (currentFirePlayerSound + 1) % FIRE_SOUND_COUNT;
        return bulletSounds[currentFirePlayerSound];
    }

    return m_sounds[type];
}

char *AssetManager::getTexturePath(TextureType type)
{
    return (char *)m_texturePaths[type];
}
char *AssetManager::getSoundPath(SoundType type)
{
    return (char *)m_soundPaths[type];
}