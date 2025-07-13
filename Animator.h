#pragma once
#include "IComponent.h"
#include "graphics.h"
/// <summary>
/// �����������ͨ���޸�����ָ�벥�Ŷ���������������ļ��غͻ��棬�κ���Ҫ�任�������Ϸ������Ҫ��Ӵ����
/// </summary>
class Animator : public IComponent
{
    public:
        /// <summary>
        /// �����黺��
        /// </summary>
        std::vector<std::shared_ptr<IMAGE>> textures;
        /// <summary>
        /// ������¼�ʱ��
        /// </summary>
        float timer=0;
        /// <summary>
        /// ��ǰʹ�õ�����ID
        /// </summary>
        float currID = 0;
        Animator(GameObject* obj);
        void Start() override;
        void UpdateLogic(float deltaTime) override;
        ~Animator() override;
        void ChangeTexture(int id);
};

