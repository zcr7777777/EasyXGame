#pragma once
#include "Transform.h"
#include "graphics.h"
#include <string>
#include <vector>
#include <exception>
#include <memory>
class IComponent; // 前置声明
/// <summary>
/// 游戏对象类，任何对象都是游戏对象，都要继承此抽象基类，必须实现所有抽象方法
/// </summary>
class GameObject
{
    public:
        /// <summary>
        /// 当前显示的纹理
        /// </summary>
        std::shared_ptr<IMAGE> texture;
        /// <summary>
        /// 游戏对象类型枚举
        /// </summary>
        enum class GameObjectType
        {
            Other = -1,
            Player = 0,
            Floor
        };
        /// <summary>
        /// 类型
        /// </summary>
        GameObjectType gameObjectType=GameObjectType::Other;
        /// <summary>
        /// 名称
        /// </summary>
        std::string name;
        /// <summary>
        /// 渲染顺序
        /// </summary>
        int renderOrder;
        /// <summary>
        /// 创建一个具有指定名称、类型和渲染顺序的 GameObject 实例
        /// </summary>
        /// <param name="name">游戏对象的名称</param>
        /// <param name="type">游戏对象的类型(GameObjectType 枚举值)</param>
        /// <param name="renderOrder">游戏对象的渲染顺序</param>
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
    /// 游戏对象包含的组件列表
    /// </summary>
    std::vector<IComponent*> components;
    public:
        Transform transform;
        /// <summary>
        /// Start函数在游戏开始运行时调用一次
        /// </summary>
        virtual void Start() = 0;
        /// <summary>
        /// UpdateLogic函数每帧调用一次，用来更新游戏逻辑
        /// </summary>
        /// <param name="deltaTime">距上一帧的时间间隔</param>
        virtual void UpdateLogic(float deltaTime) = 0;
        /// <summary>
        /// 向GameObject添加组件
        /// </summary>
        /// <param name="component">要添加的组件</param>
        void AddComponent(IComponent* component)
        {
            components.push_back(component);
        }
        /// <summary>
        /// 获取组件
        /// </summary>
        /// <typeparam name="T">组件类型</typeparam>
        /// <returns>组件</returns>
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

