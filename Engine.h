#pragma once
#include <vector>
#include "GameObject.h"
#include "Render.h"
/// <summary>
/// 游戏引擎的核心类(单例)
/// </summary>
class Engine final{
public:
    /// <summary>
    /// 获得游戏引擎单例
    /// </summary>
    /// <param name="frameScale">窗口大小</param>
    /// <returns>单例指针</returns>
    static Engine* GetInstance(Vector2 frameScale);
    /// <summary>
    /// 启动游戏引擎
    /// </summary>
    void Start();
    /// <summary>
    /// 运行游戏
    /// </summary>
    void RunTime();
    /// <summary>
    /// 将一个游戏对象添加到场景中
    /// </summary>
    /// <param name="obj">指向要添加的 GameObject 对象的指针</param>
    void AddGameObject(GameObject* obj);
    /// <summary>
    /// 释放引擎的所有资源。
    /// </summary>
    static void Dispose();
    /// <summary>
    /// 指示引擎是否正在运行
    /// </summary>
    static bool isRunning;
    /// <summary>
    /// 屏幕帧大小
    /// </summary>
    Vector2 frameScale = {0,0};
    /// <summary>
    /// 游戏对象列表
    /// </summary>
    std::vector<GameObject*> gameObjects;

private:
    static Engine* instance;

    Engine(Vector2 frameScale);
    ~Engine() = default;
    Engine(const Engine&) = delete;
    void operator=(const Engine&) = delete;
    Engine(Engine&&) = delete;
    void operator=(Engine&&) = delete;
};