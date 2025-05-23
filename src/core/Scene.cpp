#include "core/Scene.hpp"
#include "core/Globals.hpp"

Scene::Scene()
{
    m_worldId = Globals::GetWorldId();
    backgroundTexture = Globals::GetAssetManager()->getTexture(TEXTURE_SAND);
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

    m_contactEvents = b2World_GetContactEvents(m_worldId);
    for (int i = 0; i < m_contactEvents.beginCount; i++)
    {
        b2ContactBeginTouchEvent *event = &m_contactEvents.beginEvents[i];
        GameObject *objA = (GameObject *)b2Body_GetUserData(b2Shape_GetBody(event->shapeIdA));
        GameObject *objB = (GameObject *)b2Body_GetUserData(b2Shape_GetBody(event->shapeIdB));
        objA->OnCollision(objB);
        objB->OnCollision(objA);
    }

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
    for (int y = 0; y < GetScreenHeight(); y += backgroundTexture.height)
    {
        for (int x = 0; x < GetScreenWidth(); x += backgroundTexture.width)
        {
            DrawTexture(backgroundTexture, x, y, WHITE);
        }
    }
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
    Bullet *b = new Bullet(pos, rot);
    gameObjects.push_back(b);
}

void Scene::spawnTank(b2Vec2 pos, TankType type, TankColor color)
{
    Tank *tank = new Tank(pos, type, color);
    gameObjects.push_back(tank);
}