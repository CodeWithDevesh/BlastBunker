#include "core/AssetManager.hpp"

#ifdef CLIENT

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

    for (auto &bulletSound : bulletSounds)
    {
        bulletSound = LoadSound(m_soundPaths[SOUND_PLAYER_FIRE]);
        SetSoundVolume(bulletSound, 0.5f);
    }
}

AssetManager::~AssetManager()
{
    for (const auto &m_texture : m_textures)
    {
        UnloadTexture(m_texture);
    }

    for (const auto &m_sound : m_sounds)
    {
        UnloadSound(m_sound);
    }

    for (const auto &bulletSound : bulletSounds)
    {
        UnloadSound(bulletSound);
    }
}

Texture2D AssetManager::getTexture(const TextureType type) const
{
    return m_textures[type];
}

Sound AssetManager::getSound(const SoundType type)
{
    if (type == SOUND_PLAYER_FIRE)
    {
        currentFirePlayerSound = (currentFirePlayerSound + 1) % FIRE_SOUND_COUNT;
        return bulletSounds[currentFirePlayerSound];
    }

    return m_sounds[type];
}

char *AssetManager::getTexturePath(const TextureType type) const
{
    return const_cast<char *>(m_texturePaths[type]);
}

char *AssetManager::getSoundPath(const SoundType type) const
{
    return const_cast<char *>(m_soundPaths[type]);
}


#endif // CLIENT