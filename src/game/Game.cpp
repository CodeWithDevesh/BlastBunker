#include "Game.hpp"

Scene *Game::scene;

Game::Game()
{
    InitWindow(screenWidth, screenHeight, "BunkBlaster");
    SetTargetFPS(60);
    // ToggleFullscreen();
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED);
    // DisableCursor();
    // SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
    // SetMouseOffset(0, 0);
    // SetMouseScale(1, 1);

    b2SetLengthUnitsPerMeter(pixelPerMeter);

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = {0, 0};
    m_worldId = b2CreateWorld(&worldDef);
    

    textureManager = new TextureManager();
    inputManager = new InputManager();

    scene = new Scene(textureManager, inputManager, m_worldId);
    b2Vec2 pos;
    pos.x = 0;
    pos.y = 0;
    scene->spawnTank(pos);

    pos.x = 400;
    pos.y = 400;
    scene->spawnTank(pos, TANK_ENEMY);
}

Game::~Game()
{
    if(scene)
    {
        delete (scene);
        scene = nullptr;
    }
    if (textureManager)
    {
        delete (textureManager);
        textureManager = nullptr;
    }
    if (inputManager)
    {
        delete (inputManager);
        inputManager = nullptr;
    }

    b2DestroyWorld(m_worldId);
    CloseWindow();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        accumalator += GetFrameTime();
        
        while (accumalator >= fixedTimeStep)
        {
            accumalator -= fixedTimeStep;
            b2World_Step(m_worldId, fixedTimeStep, 4);
            Update();
        }
        Render();
    }
}

void Game::Update()
{
    inputManager->Update();
    scene->update();
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(YELLOW);
    DrawFPS(10, 10);
    scene->render();
    EndDrawing();
}

void Game::spwanBullet(b2Vec2 pos, float dir)
{
    scene->spawnBullet(pos, dir);
}