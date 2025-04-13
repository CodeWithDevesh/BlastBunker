#include "Game.hpp"

Game::Game()
{
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity.x = 0;
    worldDef.gravity.y = 0;
    m_b2WorldId = b2CreateWorld(&worldDef);

    
    InitWindow(screenWidth, screenHeight, "BunkBlaster");
    SetTargetFPS(60);
    HideCursor();
    ToggleFullscreen();
    b2Vec2 pos;
    pos.x = 100;
    pos.y = 100;
    tank = new Tank(m_b2WorldId, pos, 15);
}

Game::~Game()
{
    if (tank)
    {
        delete (tank);
        tank = nullptr;
    }
    b2DestroyWorld(m_b2WorldId);
    CloseWindow();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        accumalator += GetFrameTime();
        std::cout << accumalator << '\n';

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