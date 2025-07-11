#pragma once
#include "IComponent.h"
/// <summary>
/// 音频源组件
/// </summary>
class AudioSource :  public IComponent
{
public:
	AudioSource(GameObject* obj) : IComponent(obj) {}
	~AudioSource() override = default;
	void Start()override {}
	void UpdateLogic(float deltaTime)override {}
	/// <summary>
	/// 播放音频
	/// </summary>
	/// <param name="path">音频文件路径</param>
	void Play(std::string path);
};

