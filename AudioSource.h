#pragma once
#include "IComponent.h"
/// <summary>
/// ��ƵԴ���
/// </summary>
class AudioSource :  public IComponent
{
public:
	AudioSource(GameObject* obj) : IComponent(obj) {}
	~AudioSource() override = default;
	void Start()override {}
	void UpdateLogic(float deltaTime)override {}
	/// <summary>
	/// ������Ƶ
	/// </summary>
	/// <param name="path">��Ƶ�ļ�·��</param>
	void Play(std::string path);
};

