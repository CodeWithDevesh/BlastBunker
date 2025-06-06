#include "core/Globals.hpp"

b2WorldId Globals::m_worldId;

#ifdef CLIENT
AssetManager *Globals::m_assetManager = nullptr;
InputManager *Globals::m_inputManager = nullptr;
#endif

void Globals::Init()
{

#ifdef CLIENT
    m_assetManager = new AssetManager();
    m_inputManager = new InputManager();
#endif

    b2SetLengthUnitsPerMeter(pixelPerMeter);

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = {0, 0};
    m_worldId = b2CreateWorld(&worldDef);
}

void Globals::Shutdown()
{
#ifdef CLIENT
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
#endif

    b2DestroyWorld(m_worldId);
}