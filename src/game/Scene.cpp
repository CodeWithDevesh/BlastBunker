#include "Scene.hpp"

Scene::Scene(TextureManager *textureManager, InputManager* inputManager)
{
    this->textureManager = textureManager;
    this->inputManager = inputManager;
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
    printf("%d\n", gameObjects.size());
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

void Scene::spawnBullet(Vector2 pos, float rot)
{
    Bullet *b = new Bullet(pos, rot, textureManager);
    gameObjects.push_back(b);
}

void Scene::spawnTank(Vector2 pos)
{
    Tank *tank = new Tank(pos, textureManager, inputManager);
    gameObjects.push_back(tank);
}