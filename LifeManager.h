#pragma once
#include "IComponent.h"
#include "Engine.h"
#include "PictureGameObject.h"
#include "UIText.h"
class LifeManager : public IComponent
{
public:
	float leftTime = 30000;
	float showWinTime = 5000;
	bool win = false;
	LifeManager(GameObject *obj) : IComponent(obj) {}
	void Start() override;
	void Update(float deltaTime) override;
};
