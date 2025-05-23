#pragma once

#include <raylib.h>

// append new ones to the end of the enum
// don't change the order of existing ones
// And update the paths too

enum TextureType
{
    TEXTURE_TANK_GREEN_BODY,
    TEXTURE_TANK_GREEN_TURRET,
    TEXTURE_BULLET,
    TEXTURE_SAND,
    TEXTURE_EXPLOSION,
    TEXTURE_COUNT, // Keep this at the end
};

enum SoundType
{
    SOUND_EXPLOSION,
    SOUND_COUNT, // Keep this at the end
};

class AssetManager
{

public:
    AssetManager();
    ~AssetManager();

    Texture2D getTexture(TextureType type);
    Sound getSound(SoundType type);

private:
    Texture2D m_textures[TEXTURE_COUNT];
    const char *m_texturePaths[TEXTURE_COUNT] = {
        "../assets/bunker_body_green.png",
        "../assets/bunker_turret_green.png",
        "../assets/bullet.png",
        "../assets/sand.jpg",
        "../assets/explosion.png",
    };

    Sound m_sounds[SOUND_COUNT];
    const char *m_soundPaths[SOUND_COUNT] = {
        "../assets/boom.wav",
    };
};