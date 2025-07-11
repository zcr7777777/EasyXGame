#include "FloorMoving.h"
void FloorMoving::UpdateLogic(float deltaTime) {
	Vector2 frameScale = Engine::GetInstance({})->frameScale;
	Vector2 scale = gameObject->transform.scale;
	gameObject->transform.position.x += 0.1f * deltaTime * direction * speed;
	gameObject->transform.position.y += 0.02f * deltaTime;
	if (gameObject->transform.position.y > frameScale.y+scale.y/2) {
		gameObject->transform.position.y = -scale.y/2;
	}
	if (gameObject->transform.position.x < -scale.x/2)
	{
		speed = (rand() % 5 + 3.0) * 0.1;
		direction = rand() % 2 ? 1 : -1;
		if (direction == -1) {
			gameObject->transform.position.x = frameScale.x+scale.x/2;
		}
		gameObject->transform.position.y = rand() % (int)(frameScale.y-100) + 100;
	}
	if (gameObject->transform.position.x > frameScale.x+scale.x/2)
	{
		speed = (rand() % 5 + 3.0) * 0.1;
		direction = rand() % 2 ? 1 : -1;
		if (direction == 1) {
			gameObject->transform.position.x = -scale.x/2;
		}
		gameObject->transform.position.y = rand() % (int)(frameScale.y - 100) + 100;
	}
}