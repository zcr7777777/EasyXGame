#pragma once
#include "IComponent.h"
#include "Transform.h"
#include <functional>
#include <vector>
#include <algorithm>

class GameObject; // 前置声明
/// <summary>
/// 盒式碰撞器组件，用于检测碰撞，碰撞双方都应该添加此组件，如果需要碰撞物理反馈，还需要添加RigidBody组件
/// </summary>
class BoxCollider final : public IComponent
{

public:
    /// <summary>
    /// 碰撞器世界坐标
    /// </summary>
    Vector2 worldPosition;
    /// <summary>
    /// 碰撞发生方向
    /// </summary>
    Vector2 CollideDirection = { 0,0 };
    /// <summary>
    /// 场景中的所有碰撞器
    /// </summary>
    static std::vector<BoxCollider*> s_Instances;
    /// <summary>
    /// 当前正在检测的碰撞器
    /// </summary>
    std::vector<BoxCollider*> m_CurrentCollisions;
    /// <summary>
    /// 上一帧检测的碰撞器
    /// </summary>
    std::vector<BoxCollider*> m_PreviousCollisions;
    /// <summary>
    /// 触发器进入回调
    /// </summary>
    std::function<void(GameObject*)> onTriggerEnter;
    /// <summary>
    /// 触发器停留回调
    /// </summary>
    std::function<void(GameObject*)> onTriggerStay;
    /// <summary>
    /// 触发器退出回调
    /// </summary>
    std::function<void(GameObject*)> onTriggerExit;
    /// <summary>
    /// 碰撞器进入回调
    /// </summary>
    std::function<void(GameObject*)> onCollisionEnter;
    /// <summary>
    /// 碰撞器停留回调
    /// </summary>
    std::function<void(GameObject*)> onCollisionStay;
    /// <summary>
    /// 碰撞器退出回调
    /// </summary>
    std::function<void(GameObject*)> onCollisionExit;

    /// <summary>
    /// 碰撞器尺寸
    /// </summary>
    Vector2 size{ 1.0f, 1.0f };
    /// <summary>
    /// 是否为触发器(无物理效果)
    /// </summary>
    bool isTrigger{ false };

    BoxCollider(GameObject* obj,bool isTrigger=false) : IComponent(obj), isTrigger(isTrigger)
    {
        s_Instances.push_back(this);
        worldPosition = obj-> transform.position;
    }

    void Start() override
    {
        UpdateBounds();
        size = gameObject->transform.scale;
    }

    void UpdateLogic(float deltaTime) override
    {
        UpdateBounds();
        DetectCollisions();
        ProcessCollisions();
    }
    /// <summary>
    /// 更新碰撞器位置
    /// </summary>
    void UpdateBounds()
    {
        worldPosition = gameObject->transform.position;
    }
    /// <summary>
    /// 侦测是否发生碰撞并记录
    /// </summary>
    void DetectCollisions()
    {
        m_CurrentCollisions.clear();

        for (auto other : s_Instances)
        {
            if (other == this) continue;

            if (CheckCollision(*other))
            {
                m_CurrentCollisions.push_back(other);
            }
        }
    }
    /// <summary>
    /// 检测与另一个碰撞器是否发生碰撞
    /// </summary>
    /// <param name="other">另一个碰撞器</param>
    /// <returns>是否发生碰撞</returns>
    bool CheckCollision(const BoxCollider& other){
        // 计算碰撞器半尺寸
        Vector2 halfSize = size * 0.5f;
        Vector2 otherHalf = other.size * 0.5f;

        // 计算碰撞边界
        Vector2 thisMin = worldPosition - halfSize;
        Vector2 thisMax = worldPosition + halfSize;
        Vector2 otherMin = other.worldPosition - otherHalf;
        Vector2 otherMax = other.worldPosition + otherHalf;
        float dx = (thisMax.x < otherMax.x) ? thisMax.x - otherMin.x : otherMax.x - thisMin.x;
        float dy = (thisMax.y < otherMax.y) ? thisMax.y - otherMin.y : otherMax.y - thisMin.y;
        CollideDirection=Vector2(dx,dy);

        // AABB 碰撞检测(对称轴轴对齐包围盒检测法)
        return (thisMin.x <= otherMax.x && thisMax.x >= otherMin.x &&
            thisMin.y <= otherMax.y && thisMax.y >= otherMin.y);
    }

    void ProcessCollisions()
    {
        // 处理进入事件
        for (auto current : m_CurrentCollisions)
        {
            if (std::find(m_PreviousCollisions.begin(), m_PreviousCollisions.end(), current) ==
                m_PreviousCollisions.end())
            {
                TriggerEnterEvent(current);
            }
            else
            {
                TriggerStayEvent(current);
            }
        }

        // 处理退出事件
        for (auto previous : m_PreviousCollisions)
        {
            if (std::find(m_CurrentCollisions.begin(), m_CurrentCollisions.end(), previous) ==
                m_CurrentCollisions.end())
            {
                TriggerExitEvent(previous);
            }
        }

        m_PreviousCollisions = m_CurrentCollisions;
    }

    void TriggerEnterEvent(BoxCollider* other)
    {
        if (other->isTrigger)
        {
            if (onTriggerEnter) onTriggerEnter(other->gameObject);
        }
        else
        {
            if (onCollisionEnter) onCollisionEnter(other->gameObject);
        }
    }

    void TriggerStayEvent(BoxCollider* other)
    {
        if (other->isTrigger)
        {
            if (onTriggerStay) onTriggerStay(other->gameObject);
        }
        else
        {
            if (onCollisionStay) onCollisionStay(other->gameObject);
        }
    }

    void TriggerExitEvent(BoxCollider* other)
    {
        if (other->isTrigger)
        {
            if (onTriggerExit) onTriggerExit(other->gameObject);
        }
        else
        {
            if (onCollisionExit) onCollisionExit(other->gameObject);
        }
    }

    Vector2 GetWorldPosition() const
    {
        return gameObject->transform.position;
    }

    ~BoxCollider() override
    {
        auto it = std::find(s_Instances.begin(), s_Instances.end(), this);
        if (it != s_Instances.end()) s_Instances.erase(it);
    }
};