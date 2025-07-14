#include "Engine.h"
#include "BoxCollider.h"
#include "RigidBody.h"
#include "PlayerGameObject.h"
#include "WallGameObject.h"
#include "FloorMoving.h"
#include "PictureGameObject.h"
#include "UIText.h"
#include "EnemyBehavior.h"
#include "BallBehavior.h"
#include "LifeManager.h"
int main()
{
    srand(time(NULL));
    Engine* engine;

        /// **��һ�أ����ֽ̳�** ///

        // ��ʼ������
        engine = Engine::GetInstance({ 800,440 });

        // �����Ϸ����
        engine->AddGameObject(new UIText("Guide1",3,{0,0},_T("�̳̣���AD�����ƶ��������ɫ��Ծ���ո���")));
        engine->AddGameObject(new PlayerGameObject("Player", 0, { 0,300 }));
        engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 64,364 }, { 127,44 }, 0)));
        engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 191,484 }, { 127,44 }, 0)));
        engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 318,404 }, { 127,44 }, 0)));
        engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 445,324 }, { 127,44 }, 0)));
        engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 572,244 }, { 127,44 }, 0)));
        engine->AddGameObject(new WallGameObject("Floor", 1, Transform({ 699,164 }, { 127,44 }, 0)));
        engine->AddGameObject(new PictureGameObject("BackGround", -1, { 40,40 }, "Inazuma.png"));
        GameObject* e = new PictureGameObject("Elysia", 2, { 690,105 }, "Elysia.png");
        e->transform.scale = { 80,80 };
        e->AddComponent(new BoxCollider(e, true));
        e->GetComponent<BoxCollider>()->size = { 40,40 };
        engine->AddGameObject(e);

        // ������Ϸ
        engine->Start();
        engine->RunTime();

        // �ͷ�����
        Engine::Dispose();

        /// **�ڶ��� ��Ծ** ///

        // ��ʼ������
        engine = Engine::GetInstance({ 1334,467 });

        // �����Ϸ����
        engine->AddGameObject(new PictureGameObject("BackGround", -1, { 40,40 }, "ElysianRealm2.jpg"));
        engine->AddGameObject(new PlayerGameObject("Player", 0, { 0,0 }));
        for (int i = 0; i < 20; i++) {
            WallGameObject* wall = new WallGameObject("Floor" + std::to_string(i), 1, Transform({ (float)(rand() % ((int)engine->frameScale.x)),(float)(rand() % ((int)engine->frameScale.y * 2) - engine->frameScale.y) }, { 127,44 }, 0));
            wall->AddComponent(new FloorMoving(wall));
            engine->AddGameObject(wall);
        }
        e = new PictureGameObject("Elysia", 2, { 1250,120 }, "Elysia.png");
        e->AddComponent(new BoxCollider(e, true));
        engine->AddGameObject(e);

        // ������Ϸ
        engine->Start();
        engine->RunTime();

        // �ͷ�����
        Engine::Dispose();

        /// **������ BOSSս** ///

        // ��ʼ������
        engine = Engine::GetInstance({ 1920,900 });

        // �����Ϸ����
        GameObject* player = new PlayerGameObject("Player", 0, { 0,0 });
        player->AddComponent(new LifeManager(player));
        engine->AddGameObject(new UIText("Guide1", 3, { 0,0 }, _T("���30�벻�����У�")));
        e = new PictureGameObject("Enemy", 0, { 0,0 }, "enemyTexture.png");
        e->AddComponent(new EnemyBehavior(e,player));
        e->AddComponent(new RigidBody(e));
        engine->AddGameObject(e);
        engine->AddGameObject(new PictureGameObject("BackGround", -1, { 40,40 }, "ElysianRealm1.jpg"));
        engine->AddGameObject(player);
        for (int i = 0; i < 16; i++) {
            WallGameObject* wall = new WallGameObject("Floor" + std::to_string(i), 1, Transform({ (float)i*127,880 }, { 127,44 }, 0));
            engine->AddGameObject(wall);
        }
        for (int i = 0; i < 5; i++) {
            GameObject* ball;
            ball = new PictureGameObject("Ball" + std::to_string(i),2,{0,0},"ball.png");
            ball->gameObjectType=GameObject::GameObjectType::Ball;
            ball->AddComponent(new RigidBody(ball));
            BoxCollider* collider = new BoxCollider(ball);
            collider->isTrigger = true;
            ball->AddComponent(collider);
            ball->AddComponent(new BallBehavior(ball,e));
            e->GetComponent<EnemyBehavior>()->balls.push_back(ball->GetComponent<BallBehavior>());
            engine->AddGameObject(ball);
        }

        // ������Ϸ
        engine->Start();
        engine->RunTime();

        // �ͷ�����
        Engine::Dispose();
    return 0;
}