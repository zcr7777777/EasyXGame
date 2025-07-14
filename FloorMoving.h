#pragma once
#include "IComponent.h"
#include "Engine.h"
#include "RigidBody.h"
/// <summary>
/// 地板移动组件，用于控制地板随机移动
/// </summary>
class FloorMoving : public IComponent
{
public:
	/// <summary>
	/// 左右移动方向
	/// </summary>
	int direction=rand()%4?-1:1;
    /// <summary>
	/// 左右移动速度
	/// </summary>
	float speed = (rand()%5+3.0)*0.1;
	FloorMoving(GameObject* obj) : IComponent(obj) {}
	~FloorMoving() override= default;
	void Start()override {}
	void Update(float deltaTime)override;
};

