#include "FloorMoving.h"
void FloorMoving::Update(float deltaTime) {
	Vector2 frameScale = Engine::GetInstance({})->frameScale;
	Vector2 scale = gameObject->transform.scale;
	gameObject->GetComponent<RigidBody>()->velocity = { 0.1f * direction * speed,0.02f };
	if (gameObject->transform.position.y > frameScale.y+scale.y/2) {
		gameObject->transform.position.y = -scale.y/2;
	}
	if (gameObject->transform.position.x < -scale.x/2)
	{
		speed = (rand() % 10 + 3.0) * 0.1;
		direction = rand() % 3 ? -1 :1;
		if (direction == -1) {
			gameObject->transform.position.x = frameScale.x+scale.x/2;
		}
		gameObject->transform.position.y = rand() % (int)(frameScale.y-100) + 100;
	}
	if (gameObject->transform.position.x > frameScale.x+scale.x/2)
	{
		speed = (rand() % 10 + 3.0) * 0.1;
		direction = rand() % 3 ? -1 : 1;
		if (direction == 1) {
			gameObject->transform.position.x = -scale.x/2;
		}
		gameObject->transform.position.y = rand() % (int)(frameScale.y - 100) + 100;
	}
}