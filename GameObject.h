#pragma once
#include "Transform.h"
#include "graphics.h"
#include <string>
#include <vector>
#include <exception>
#include <memory>
class IComponent; // ǰ������
/// <summary>
/// ��Ϸ�����࣬�κζ�������Ϸ���󣬶�Ҫ�̳д˳�����࣬����ʵ�����г��󷽷�
/// </summary>
class GameObject
{
    public:
        /// <summary>
        /// ��ǰ��ʾ������
        /// </summary>
        std::shared_ptr<IMAGE> texture;
        /// <summary>
        /// ��Ϸ��������ö��
        /// </summary>
        enum class GameObjectType
        {
            Other = -1,
            Player = 0,
            Floor
        };
        /// <summary>
        /// ����
        /// </summary>
        GameObjectType gameObjectType=GameObjectType::Other;
        /// <summary>
        /// ����
        /// </summary>
        std::string name;
        /// <summary>
        /// ��Ⱦ˳��
        /// </summary>
        int renderOrder;
        /// <summary>
        /// ����һ������ָ�����ơ����ͺ���Ⱦ˳��� GameObject ʵ��
        /// </summary>
        /// <param name="name">��Ϸ���������</param>
        /// <param name="type">��Ϸ���������(GameObjectType ö��ֵ)</param>
        /// <param name="renderOrder">��Ϸ�������Ⱦ˳��</param>
        GameObject(std::string name,GameObjectType type,int renderOrder):name(name),gameObjectType(type),renderOrder(renderOrder){}
        virtual ~GameObject()
        {
            for (auto component : components)
            {
                delete component;
            }
        }
protected:
    /// <summary>
    /// ��Ϸ�������������б�
    /// </summary>
    std::vector<IComponent*> components;
    public:
        Transform transform;
        /// <summary>
        /// Start��������Ϸ��ʼ����ʱ����һ��
        /// </summary>
        virtual void Start() = 0;
        /// <summary>
        /// UpdateLogic����ÿ֡����һ�Σ�����������Ϸ�߼�
        /// </summary>
        /// <param name="deltaTime">����һ֡��ʱ����</param>
        virtual void UpdateLogic(float deltaTime) = 0;
        /// <summary>
        /// ��GameObject������
        /// </summary>
        /// <param name="component">Ҫ��ӵ����</param>
        void AddComponent(IComponent* component)
        {
            components.push_back(component);
        }
        /// <summary>
        /// ��ȡ���
        /// </summary>
        /// <typeparam name="T">�������</typeparam>
        /// <returns>���</returns>
        template<typename T>  
        T* GetComponent()  
        {  
            for (auto* component : components)  
            {  
                T* castedComponent = dynamic_cast<T*>(component);  
                if (castedComponent != nullptr)  
                {  
                    return castedComponent;  
                }  
            }  
            throw "Component not found";
            return nullptr;  
        }
};

