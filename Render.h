#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "graphics.h"
#include "GameObject.h"
#include "Engine.h"
/// <summary>
/// ��Ⱦģ�飬����ȫ�ֻ��ƿ���
/// </summary>
namespace Render {
	/// <summary>
	/// ���ھ��
	/// </summary>
	extern HWND windowHandle;
	/// <summary>
	/// ��ʼ����Ⱦģ��
	/// </summary>
	/// <param name="frameScale">���ڴ�С</param>
	void Initialize(Vector2 frameScale);
	/// <summary>
	/// ÿ֡��Ⱦǰ����һ��
	/// </summary>
	/// <param name="fps">֡��</param>
	void BeginFrame(float fps);
    /// <summary>
	/// ��Ⱦ������Ϸ����
	/// </summary>
	void RenderGameObjects();
    /// <summary>
    /// ��Ⱦһ����Ϸ����
    /// </summary>
    /// <param name="gameObject"></param>
    void RenderGameObject(GameObject* gameObject);
    /// <summary>
    /// ÿ֡��Ⱦ�����һ��
    /// </summary>
    void EndFrame();
	/// <summary>
	/// �ͷ���Ⱦģ�������Դ
	/// </summary>
	void Dispose();
}

