#pragma once
#include "IComponent.h"
#include "Transform.h"
#include <functional>
#include <vector>
#include <algorithm>

class GameObject; // ǰ������
/// <summary>
/// ��ʽ��ײ����������ڼ����ײ����ײ˫����Ӧ����Ӵ�����������Ҫ��ײ������������Ҫ���RigidBody���
/// </summary>
class BoxCollider final : public IComponent
{

public:
    /// <summary>
    /// ��ײ����������
    /// </summary>
    Vector2 worldPosition;
    /// <summary>
    /// ��ײ��������
    /// </summary>
    Vector2 CollideDirection = { 0,0 };
    /// <summary>
    /// �����е�������ײ��
    /// </summary>
    static std::vector<BoxCollider*> s_Instances;
    /// <summary>
    /// ��ǰ���ڼ�����ײ��
    /// </summary>
    std::vector<BoxCollider*> m_CurrentCollisions;
    /// <summary>
    /// ��һ֡������ײ��
    /// </summary>
    std::vector<BoxCollider*> m_PreviousCollisions;
    /// <summary>
    /// ����������ص�
    /// </summary>
    std::function<void(GameObject*)> onTriggerEnter;
    /// <summary>
    /// ������ͣ���ص�
    /// </summary>
    std::function<void(GameObject*)> onTriggerStay;
    /// <summary>
    /// �������˳��ص�
    /// </summary>
    std::function<void(GameObject*)> onTriggerExit;
    /// <summary>
    /// ��ײ������ص�
    /// </summary>
    std::function<void(GameObject*)> onCollisionEnter;
    /// <summary>
    /// ��ײ��ͣ���ص�
    /// </summary>
    std::function<void(GameObject*)> onCollisionStay;
    /// <summary>
    /// ��ײ���˳��ص�
    /// </summary>
    std::function<void(GameObject*)> onCollisionExit;

    /// <summary>
    /// ��ײ���ߴ�
    /// </summary>
    Vector2 size{ 1.0f, 1.0f };
    /// <summary>
    /// �Ƿ�Ϊ������(������Ч��)
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
    /// ������ײ��λ��
    /// </summary>
    void UpdateBounds()
    {
        worldPosition = gameObject->transform.position;
    }
    /// <summary>
    /// ����Ƿ�����ײ����¼
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
    /// �������һ����ײ���Ƿ�����ײ
    /// </summary>
    /// <param name="other">��һ����ײ��</param>
    /// <returns>�Ƿ�����ײ</returns>
    bool CheckCollision(const BoxCollider& other){
        // ������ײ����ߴ�
        Vector2 halfSize = size * 0.5f;
        Vector2 otherHalf = other.size * 0.5f;

        // ������ײ�߽�
        Vector2 thisMin = worldPosition - halfSize;
        Vector2 thisMax = worldPosition + halfSize;
        Vector2 otherMin = other.worldPosition - otherHalf;
        Vector2 otherMax = other.worldPosition + otherHalf;
        float dx = (thisMax.x < otherMax.x) ? thisMax.x - otherMin.x : otherMax.x - thisMin.x;
        float dy = (thisMax.y < otherMax.y) ? thisMax.y - otherMin.y : otherMax.y - thisMin.y;
        CollideDirection=Vector2(dx,dy);

        // AABB ��ײ���(�Գ���������Χ�м�ⷨ)
        return (thisMin.x <= otherMax.x && thisMax.x >= otherMin.x &&
            thisMin.y <= otherMax.y && thisMax.y >= otherMin.y);
    }

    void ProcessCollisions()
    {
        // ��������¼�
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

        // �����˳��¼�
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