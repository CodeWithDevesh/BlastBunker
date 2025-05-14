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

    textureManager = new TextureManager();

    scene = new Scene(textureManager);
    Vector2 pos;
    pos.x = 100;
    pos.y = 100;
    scene->spawnTank(pos);
}

Game::~Game()
{
    if (textureManager)
    {
        delete (textureManager);
        textureManager = nullptr;
    }

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
        }
        Render();
    }
}

void Game::Update()
{
    scene->update();
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    scene->render();
    EndDrawing();
}

void Game::spwanBullet(Vector2 pos, float dir)
{
    scene->spawnBullet(pos, dir);
}