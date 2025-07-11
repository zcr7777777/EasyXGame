#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "graphics.h"
#include "GameObject.h"
#include "Engine.h"
/// <summary>
/// 渲染模块，用于全局绘制控制
/// </summary>
namespace Render {
	/// <summary>
	/// 窗口句柄
	/// </summary>
	extern HWND windowHandle;
	/// <summary>
	/// 初始化渲染模块
	/// </summary>
	/// <param name="frameScale">窗口大小</param>
	void Initialize(Vector2 frameScale);
	/// <summary>
	/// 每帧渲染前调用一次
	/// </summary>
	/// <param name="fps">帧率</param>
	void BeginFrame(float fps);
    /// <summary>
	/// 渲染所有游戏对象
	/// </summary>
	void RenderGameObjects();
    /// <summary>
    /// 渲染一个游戏对象
    /// </summary>
    /// <param name="gameObject"></param>
    void RenderGameObject(GameObject* gameObject);
    /// <summary>
    /// 每帧渲染后调用一次
    /// </summary>
    void EndFrame();
	/// <summary>
	/// 释放渲染模块相关资源
	/// </summary>
	void Dispose();
}

