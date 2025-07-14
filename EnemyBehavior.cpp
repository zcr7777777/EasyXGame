#include "EnemyBehavior.h"
void EnemyBehavior::Start()
{ 
	gameObject->transform.position = { (float)(1200 + rand() % 200),(float)(100 + rand() % 100) };
	gameObject->transform.scale = { 100,200 };
}
void EnemyBehavior::Update(float deltaTime)
{
    if (abs(gameObject->transform.position.x - player->transform.position.x) > 10) {
        if (gameObject->transform.position.x > player->transform.position.x) {
            gameObject->GetComponent<RigidBody>()->velocity = { -0.05f,0 };
        }
        else {
            gameObject->GetComponent<RigidBody>()->velocity = { 0.05f,0 };
        }
    }
   	timer += deltaTime;
    if (timer > 800)
    { 
		timer = 0;
		currBall++;
        if (currBall >= balls.size())
        {
            currBall = 0;
        }
        balls[currBall]->StartShoot(gameObject->transform.position,player->transform.position);
    }
}