#include "core/Game.hpp"
#include "core/Globals.hpp"
#include "game/Tank.hpp"

Scene *Game::scene;
float Game::accumalator = 0;
InputManager *Game::m_inputManager;
b2WorldId Game::m_worldId;

void Game::init(){
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
}

void Game::uninit() {
  if (scene) {
    delete (scene);
    scene = nullptr;
  }

  Globals::Shutdown();
  CloseAudioDevice();
  CloseWindow();
}

void Game::run() {
  while (!WindowShouldClose()) {
    accumalator += GetFrameTime();

    while (accumalator >= fixedTimeStep) {
      accumalator -= fixedTimeStep;
      b2World_Step(m_worldId, fixedTimeStep, 4);
      Update();
    }
    Render();
  }
}

void Game::setScene(Scene *scene) {
  delete Game::scene;
  Game::scene = scene;
}

void Game::Update() {
  m_inputManager->Update();
  scene->update();
}

void Game::Render() {
  BeginDrawing();
  ClearBackground(BLACK);
  // DrawFPS(10, 10);
  scene->render();
  EndDrawing();
}

void Game::addGameObject(GameObject *obj) { scene->addGameObject(obj); }

Scene *Game::getCurrentScene() { return scene; }
