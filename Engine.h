#pragma once
#include <vector>
#include "GameObject.h"
#include "Render.h"
/// <summary>
/// ��Ϸ����ĺ�����(����)
/// </summary>
class Engine final{
public:
    /// <summary>
    /// �����Ϸ���浥��
    /// </summary>
    /// <param name="frameScale">���ڴ�С</param>
    /// <returns>����ָ��</returns>
    static Engine* GetInstance(Vector2 frameScale);
    /// <summary>
    /// ������Ϸ����
    /// </summary>
    void Start();
    /// <summary>
    /// ������Ϸ
    /// </summary>
    void RunTime();
    /// <summary>
    /// ��һ����Ϸ������ӵ�������
    /// </summary>
    /// <param name="obj">ָ��Ҫ��ӵ� GameObject �����ָ��</param>
    void AddGameObject(GameObject* obj);
    /// <summary>
    /// �ͷ������������Դ��
    /// </summary>
    static void Dispose();
    /// <summary>
    /// ָʾ�����Ƿ���������
    /// </summary>
    static bool isRunning;
    /// <summary>
    /// ��Ļ֡��С
    /// </summary>
    Vector2 frameScale = {0,0};
    /// <summary>
    /// ��Ϸ�����б�
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