#include "raylib.h"

int main() {
    InitWindow(800, 600, "BlastBunker");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to Blast Bunker!", 200, 250, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
