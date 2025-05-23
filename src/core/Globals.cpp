#include "core/Globals.hpp"


AssetManager* Globals::m_assetManager = nullptr;
InputManager* Globals::m_inputManager = nullptr;
b2WorldId Globals::m_worldId;


void Globals::Init()
{
    m_assetManager = new AssetManager();
    m_inputManager = new InputManager();

    b2SetLengthUnitsPerMeter(pixelPerMeter);

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = {0, 0};
    m_worldId = b2CreateWorld(&worldDef);
}

void Globals::Shutdown()
{
    if (m_assetManager)
    {
        delete m_assetManager;
        m_assetManager = nullptr;
    }
    if (m_inputManager)
    {
        delete m_inputManager;
        m_inputManager = nullptr;
    }
    b2DestroyWorld(m_worldId);
}