#pragma once
#include "IComponent.h"
#include "Engine.h"
#include "RigidBody.h"
/// <summary>
/// �ذ��ƶ���������ڿ��Ƶذ�����ƶ�
/// </summary>
class FloorMoving : public IComponent
{
public:
	/// <summary>
	/// �����ƶ�����
	/// </summary>
	int direction=rand()%4?-1:1;
    /// <summary>
	/// �����ƶ��ٶ�
	/// </summary>
	float speed = (rand()%5+3.0)*0.1;
	FloorMoving(GameObject* obj) : IComponent(obj) {}
	~FloorMoving() override= default;
	void Start()override {}
	void Update(float deltaTime)override;
};

