#pragma once
#include "GameObject.h"
/// <summary>
/// 组件接口，所有挂载到游戏对象上的组件都必须实现本接口，游戏对象的一切行为都应当通过组件实现
/// </summary>
class IComponent
{
protected:
	/// <summary>
	/// 绑定此组件的游戏对象
	/// </summary>
	GameObject *gameObject;

public:
	/// <summary>
	/// 创建组件
	/// </summary>
	/// <param name="obj">绑定此组件的游戏对象</param>
	IComponent(GameObject *obj) : gameObject(obj) {}
	/// <summary>
	/// 组件析构方法
	/// </summary>
	virtual ~IComponent() = default;
	/// <summary>
	/// 在游戏对象Start方法后调用一次
	/// </summary>
	virtual void Start() = 0;
	/// <summary>
	/// 每帧更新后，在游戏对象UpdateLogic方法后调用一次
	/// </summary>
	/// <param name="deltaTime">时间间隔</param>
	virtual void Update(float deltaTime) = 0;
};