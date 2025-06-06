#pragma once

#include <vector>
#include "Scene.hpp"
#ifdef CLIENT
#include "InputManager.hpp"
#include <raylib.h>
#endif

#include "box2d/box2d.h"

class Game
{
private:
public:
    Game(/* args */);
    void run();
    ~Game();
    static void spwanBullet(b2Vec2 pos, float dir);
    static inline void quit()
    {
        isRunning = false;
    }

private:
    void Update();
    void Render();

    b2WorldId m_worldId;

#ifdef CLIENT
    InputManager *m_inputManager;
#endif

    static Scene *scene;
    static bool isRunning;
    float accumalator = 0;
};
