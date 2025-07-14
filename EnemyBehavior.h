#pragma once
#include "IComponent.h"
#include "BallBehavior.h"
class EnemyBehavior : public IComponent
{
public:
	std::vector<BallBehavior *> balls;
	GameObject *player;
	float timer = 0;
	int currBall = 0;
	EnemyBehavior(GameObject *obj, GameObject *player) : IComponent(obj), player(player) {}
	void Start() override;
	void Update(float deltaTime) override;
};
