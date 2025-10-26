#pragma once
#include "InputManager.hpp"
#include "Scene.hpp"

class Game {
private:
public:
  static void run();
  static void addGameObject(GameObject *obj);
  static void setScene(Scene *scene);
  static Scene *getCurrentScene();
  static void init();
  static void uninit();

private:
  Game() = delete;
  ~Game() = delete;
  static void Update();
  static void Render();

  static b2WorldId m_worldId;

  static InputManager *m_inputManager;

  static Scene *scene;

  static float accumalator;
};
