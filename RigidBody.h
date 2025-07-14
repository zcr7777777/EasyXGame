#pragma once
#include "IComponent.h"
#include "Transform.h"
/// <summary>
/// 刚体组件，模拟物理效果
/// </summary>
class RigidBody final: public IComponent
{
    public:
        /// <summary>
        /// 速度
        /// </summary>
        Vector2 velocity = {0,0};
        /// <summary>
        /// 加速度
        /// </summary>
        Vector2 acceleration = {0,0.001f};
        void Start() override;
        void Update(float deltaTime) override;
        /// <summary>
        /// 对刚体施加一个力
        /// </summary>
        /// <param name="force">力</param>
        void AddForce(Vector2 force);
        RigidBody(GameObject* obj) : IComponent(obj) {}
        ~RigidBody() override = default;
};

