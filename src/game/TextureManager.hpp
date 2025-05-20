#pragma once

#include <raylib.h>


enum TextureType
{
    TEXTURE_TANK_GREEN_BODY,
    TEXTURE_TANK_GREEN_TURRET,
    TEXTURE_BULLET,
};

class TextureManager{

    public:
        TextureManager();
        ~TextureManager();

        Texture2D getTexture(TextureType type);

    private:
        Texture2D m_textures[3];
        const char* m_texturePaths[3] = {
            "../assets/bunker_body_green.png",
            "../assets/bunker_turret_green.png",
            "../assets/bullet.png"
        };
};