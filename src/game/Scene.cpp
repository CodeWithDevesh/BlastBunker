#include "Scene.hpp"

Scene::Scene(TextureManager *manager, b2WorldId world)
{
    textureManager = manager;
    this->world = world;
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

        // Debug log to track objects
        if (obj)
        {
            printf("Updating object: %p, isAlive: %d\n", obj, obj->isAlive);
        }
        else
        {
            printf("Found null object in gameObjects vector.\n");
        }
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

void Scene::spawnBullet(b2Vec2 pos, b2Rot rot)
{
    Bullet *b = new Bullet(world, pos, rot, textureManager);
    gameObjects.push_back(b);
}

void Scene::spawnTank(b2Vec2 pos)
{
    Tank *tank = new Tank(world, pos, textureManager);
    gameObjects.push_back(tank);
}