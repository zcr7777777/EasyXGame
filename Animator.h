#pragma once
#include "IComponent.h"
#include "graphics.h"
/// <summary>
/// 动画机组件，通过修改纹理指针播放动画，并负责纹理的加载和缓存，任何需要变换纹理的游戏对象都需要添加此组件
/// </summary>
class Animator : public IComponent
{
    public:
        /// <summary>
        /// 纹理组缓存
        /// </summary>
        std::vector<std::shared_ptr<IMAGE>> textures;
        /// <summary>
        /// 纹理更新计时器
        /// </summary>
        float timer=0;
        /// <summary>
        /// 当前使用的纹理ID
        /// </summary>
        float currID = 0;
        Animator(GameObject* obj);
        void Start() override;
        void UpdateLogic(float deltaTime) override;
        ~Animator() override;
        void ChangeTexture(int id);
};

