#pragma once
#include "box2d/box2d.h"
#include "core/AssetManager.hpp"
#include "core/InputManager.hpp"

const float fixedTimeStep = 1.0f / 60.0f;
const float pixelPerMeter = 32.0f;
const float screenHeight = 480;
const float screenWidth = 640;


class Globals
{
public:
    static void Init();
    static AssetManager* GetAssetManager() { return m_assetManager; }
    static InputManager* GetInputManager() { return m_inputManager; }
    static b2WorldId GetWorldId() { return m_worldId; }
    static void Shutdown();


private:
    static b2WorldId m_worldId;
    static AssetManager *m_assetManager;
    static InputManager *m_inputManager;
};