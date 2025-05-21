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
};

class AssetManager{

    public:
        AssetManager();
        ~AssetManager();

        Texture2D getTexture(TextureType type);

    private:
        Texture2D m_textures[4];
        const char* m_texturePaths[4] = {
            "../assets/bunker_body_green.png",
            "../assets/bunker_turret_green.png",
            "../assets/bullet.png",
            "../assets/sand.jpg",
        };
};