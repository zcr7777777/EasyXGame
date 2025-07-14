#pragma once
#include "IComponent.h"
#include "Transform.h"
/// <summary>
/// ���������ģ������Ч��
/// </summary>
class RigidBody final: public IComponent
{
    public:
        /// <summary>
        /// �ٶ�
        /// </summary>
        Vector2 velocity = {0,0};
        /// <summary>
        /// ���ٶ�
        /// </summary>
        Vector2 acceleration = {0,0.001f};
        void Start() override;
        void Update(float deltaTime) override;
        /// <summary>
        /// �Ը���ʩ��һ����
        /// </summary>
        /// <param name="force">��</param>
        void AddForce(Vector2 force);
        RigidBody(GameObject* obj) : IComponent(obj) {}
        ~RigidBody() override = default;
};

