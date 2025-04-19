#include "Game.hpp"

Game::Game()
{
    b2SetLengthUnitsPerMeter(32);
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity.x = 0;
    worldDef.gravity.y = 0;
    m_b2WorldId = b2CreateWorld(&worldDef);

    InitWindow(screenWidth, screenHeight, "BunkBlaster");
    SetTargetFPS(60);
    // ToggleFullscreen();
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED);
    DisableCursor();
    SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
    SetMouseOffset(0, 0);
    SetMouseScale(1, 1);

    textureManager = new TextureManager();

    b2Vec2 pos;
    pos.x = 0;
    pos.y = 0;
    tank = new Tank(m_b2WorldId, pos, textureManager);
}

Game::~Game()
{
    if (tank)
    {
        delete (tank);
        tank = nullptr;
    }
    if(textureManager)
    {
        delete (textureManager);
        textureManager = nullptr;
    }

    b2DestroyWorld(m_b2WorldId);
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
            Update();
            b2World_Step(m_b2WorldId, fixedTimeStep, 4);
        }
        Render();
    }
}

void Game::Update()
{
    tank->Update();
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    tank->Draw();

    EndDrawing();
}