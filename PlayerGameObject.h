#pragma once
#include "GameObject.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "Animator.h"
#include "AudioSource.h"
#include "Engine.h"
#include "LifeManager.h"
#include <set>
class BoxCollider; // ǰ������
/// <summary>
/// �����Ϸ������
/// </summary>
class PlayerGameObject final : public GameObject
{
private:
    RigidBody *rigidBody = nullptr;
    BoxCollider *boxCollider = nullptr;
    Animator *animator = nullptr;
    AudioSource *audioSource = nullptr;
    bool onGround = false;
    bool canJump = false;

public:
    PlayerGameObject(std::string name, int renderOrder, Vector2 pos);
    void Start() override;
    void Update(float deltaTime) override;
    std::set<GameObject *> sideCollider;
    std::set<GameObject *> groundCollider;
    /// <summary>
    /// ��ײ������ص�
    /// </summary>
    /// <param name="other">������ײ����Ϸ����</param>
    void OnCollisionEnter(GameObject *other);
    /// <summary>
    /// ��ײ��ͣ���ص�
    /// </summary>
    /// <param name="other">������ײ����Ϸ����</param>
    void OnCollisionStay(GameObject *other);
    /// <summary>
    /// ��ײ���˳��ص�
    /// </summary>
    /// <param name="other">������ײ����Ϸ����</param>
    void OnCollisionExit(GameObject *other);
    /// <summary>
    /// ����������ص�
    /// </summary>
    /// <param name="other">������ײ����Ϸ����</param>
    void OnTriggerEnter(GameObject *other);
    ~PlayerGameObject() override = default;
};
