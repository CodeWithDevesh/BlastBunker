#include "core/Game.hpp"
#include "game/Tank.hpp"

int main() {
  Scene* scene = new Scene();
  b2Vec2 pos;
  pos.x = 100;
  pos.y = 100;
  scene->addGameObject(new Tank(pos));

  pos.x = 400;
  pos.y = 400;
  scene->addGameObject(new Tank(pos, TANK_ENEMY));

  Game::init();
  Game::setScene(scene);
  Game::run();
  Game::uninit();
  return 0;
}
