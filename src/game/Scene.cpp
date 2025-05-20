#include "Scene.hpp"

Scene::Scene(TextureManager *textureManager, InputManager *inputManager, b2WorldId worldId)
{
    this->textureManager = textureManager;
    this->inputManager = inputManager;
    m_worldId = worldId;
}

Scene::~Scene()
{
    for (auto x : gameObjects)
    {
        x->Destroy();
        delete x;
    }
}

void Scene::update()
{
    for (int i = 0; i < gameObjects.size();)
    {
        GameObject *obj = gameObjects[i];

        if (!obj)
        {
            gameObjects.erase(gameObjects.begin() + i);
            continue;
        };
        if (!(obj->isAlive))
        {
            delete obj;
            gameObjects.erase(gameObjects.begin() + i);
        }
        else
        {
            obj->Update();
            i++;
        }
    }
}

void Scene::render()
{
    for (auto it = gameObjects.begin(); it != gameObjects.end();)
    {
        GameObject *obj = *it;
        if (!obj)
        {
            it = gameObjects.erase(it);
            continue;
        };
        if (!obj->isAlive)
        {
            delete obj;
            it = gameObjects.erase(it);
        }
        else
        {
            obj->Draw();
            ++it;
        }
    }
}

void Scene::spawnBullet(b2Vec2 pos, float rot)
{
    Bullet *b = new Bullet(m_worldId, pos, rot, textureManager);
    gameObjects.push_back(b);
}

void Scene::spawnTank(b2Vec2 pos, TankType type, TankColor color)
{
    Tank *tank = new Tank(m_worldId, pos, textureManager, inputManager, type, color);
    gameObjects.push_back(tank);
}