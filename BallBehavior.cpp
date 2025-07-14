#include "BallBehavior.h"
void BallBehavior::Start()
{
    gameObject->transform.position = { -100,-100 };
}
void BallBehavior::Update(float deltaTime){
    gameObject->GetComponent<RigidBody>()->velocity = v;
}
void BallBehavior::StartShoot(Vector2 startPos, Vector2 endPos)
{
    gameObject->transform.position = startPos;
    v = Vector2((endPos - startPos).Normalize());
}