#pragma once
#include "GameObject.h"
/// <summary>
/// ����ӿڣ����й��ص���Ϸ�����ϵ����������ʵ�ֱ��ӿڣ���Ϸ�����һ����Ϊ��Ӧ��ͨ�����ʵ��
/// </summary>
class IComponent
{
protected:
	/// <summary>
	/// �󶨴��������Ϸ����
	/// </summary>
	GameObject *gameObject;

public:
	/// <summary>
	/// �������
	/// </summary>
	/// <param name="obj">�󶨴��������Ϸ����</param>
	IComponent(GameObject *obj) : gameObject(obj) {}
	/// <summary>
	/// �����������
	/// </summary>
	virtual ~IComponent() = default;
	/// <summary>
	/// ����Ϸ����Start���������һ��
	/// </summary>
	virtual void Start() = 0;
	/// <summary>
	/// ÿ֡���º�����Ϸ����UpdateLogic���������һ��
	/// </summary>
	/// <param name="deltaTime">ʱ����</param>
	virtual void Update(float deltaTime) = 0;
};