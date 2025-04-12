#include "Game.hpp"

Game::Game(){
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);         
}

Game::~Game(){
    CloseWindow();
}

void Game::run(){
    while (!WindowShouldClose()) {
        Update();
        Render();
    }
}

void Game::Update(){
    // Update game logic here
}
void Game::Render(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Welcome to the Tank Game!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}