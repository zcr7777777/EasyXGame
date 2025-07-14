#pragma once
#include "GameObject.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "Animator.h"
#include "AudioSource.h"
#include "Engine.h"
#include "LifeManager.h"
#include <set>
class BoxCollider; // 前置声明
/// <summary>
/// 玩家游戏对象类
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
    /// 碰撞器进入回调
    /// </summary>
    /// <param name="other">触发碰撞的游戏对象</param>
    void OnCollisionEnter(GameObject *other);
    /// <summary>
    /// 碰撞器停留回调
    /// </summary>
    /// <param name="other">触发碰撞的游戏对象</param>
    void OnCollisionStay(GameObject *other);
    /// <summary>
    /// 碰撞器退出回调
    /// </summary>
    /// <param name="other">触发碰撞的游戏对象</param>
    void OnCollisionExit(GameObject *other);
    /// <summary>
    /// 触发器进入回调
    /// </summary>
    /// <param name="other">触发碰撞的游戏对象</param>
    void OnTriggerEnter(GameObject *other);
    ~PlayerGameObject() override = default;
};
