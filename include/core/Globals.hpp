#pragma once
#include "box2d/box2d.h"

#ifdef CLIENT
#include "core/InputManager.hpp"
#include "core/AssetManager.hpp"
#endif

const float fixedTimeStep = 1.0f / 60.0f;
const float pixelPerMeter = 32.0f;
const float screenHeight = 480;
const float screenWidth = 640;

class Globals
{
public:
    static void Init();

    static b2WorldId GetWorldId() { return m_worldId; }
    static void Shutdown();

#ifdef CLIENT
    static AssetManager *GetAssetManager() { return m_assetManager; }
    static InputManager *GetInputManager() { return m_inputManager; }
#endif

private:
    static b2WorldId m_worldId;

#ifdef CLIENT
    static AssetManager *m_assetManager;
    static InputManager *m_inputManager;
#endif
};