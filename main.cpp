#include "Engine.h"
#include "BoxCollider.h"
#include "RigidBody.h"
#include "PlayerGameObject.h"
#include "WallGameObject.h"
#include "FloorMoving.h"
#include "PictureGameObject.h"
int main()
{
    /// **第一关：新手教程** ///

    // 初始化引擎
    Engine* engine = Engine::GetInstance({800,440});

    // 添加游戏对象
    engine->AddGameObject(new PlayerGameObject("Player", 0, {0,300}));
    engine->AddGameObject(new WallGameObject("Floor", 1, Transform({64,364}, { 127,44 }, 0)));
    engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 191,484 }, { 127,44 }, 0)));
    engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 318,404 }, { 127,44 }, 0)));
    engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 445,324 }, { 127,44 }, 0)));
    engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 572,244 }, { 127,44 }, 0)));
    engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 699,164 }, { 127,44 }, 0)));
    engine->AddGameObject(new PictureGameObject(-1, {0,0},"Inazuma.png"));

    // 运行游戏
    engine->Start();
    engine->RunTime();

    // 释放引擎
    Engine::Dispose();

    /// **第二关** ///

    // 初始化引擎
    engine = Engine::GetInstance({ 1536,864 });

    // 添加游戏对象
    engine->AddGameObject(new PlayerGameObject("Player", 0, {0,0}));
    for (int i = 0; i < 50; i++) {
        WallGameObject* wall = new WallGameObject("Floor" + std::to_string(i), 1, Transform({ (float)(rand() % ((int)engine->frameScale.x)),(float)(rand() % ((int)engine->frameScale.y * 2) - engine->frameScale.y) }, { 127,44 }, 0));
        wall->AddComponent(new FloorMoving(wall));
        engine->AddGameObject(wall);
    }

    // 运行游戏
    engine->Start();
    engine->RunTime();

    // 释放引擎
    Engine::Dispose();
    return 0;
}