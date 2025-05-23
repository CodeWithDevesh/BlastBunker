#include "core/Game.hpp"
#include "core/Globals.hpp"

Scene *Game::scene;

Game::Game()
{
    InitWindow(screenWidth, screenHeight, "BunkBlaster");
    InitAudioDevice();
    SetTargetFPS(60);
    // ToggleFullscreen();
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED);
    // DisableCursor();
    // SetWindowState(FLAG_WINDOW_MOUSE_PASSTHROUGH);
    // SetMouseOffset(0, 0);
    // SetMouseScale(1, 1);

    Globals::Init();
    m_worldId = Globals::GetWorldId();
    m_inputManager = Globals::GetInputManager();

    scene = new Scene();
    b2Vec2 pos;
    pos.x = 100;
    pos.y = 100;
    scene->spawnTank(pos);

    pos.x = 400;
    pos.y = 400;
    scene->spawnTank(pos, TANK_ENEMY);
}

Game::~Game()
{
    if (scene)
    {
        delete (scene);
        scene = nullptr;
    }

    Globals::Shutdown();
    CloseAudioDevice();
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
    m_inputManager->Update();
    scene->update();
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);
    // DrawFPS(10, 10);
    scene->render();
    EndDrawing();
}

void Game::spwanBullet(b2Vec2 pos, float dir)
{
    scene->spawnBullet(pos, dir);
}