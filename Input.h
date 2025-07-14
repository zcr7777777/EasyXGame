#pragma once
#include "Transform.h"
/// <summary>
/// 输入类，封装所有需要的输入信息
/// </summary>
class Input
{
public:
	/// <summary>
	/// 判断指定的按键是否被按下。
	/// </summary>
	/// <param name="key">要检测的按键的键码</param>
	/// <returns>如果按键被按下则返回true否则返回false</returns>
	static bool GetKey(int key);
	/// <summary>
	/// 获取鼠标的当前位置
	/// </summary>
	/// <returns>表示鼠标当前位置的 Vector2 对象</returns>
	static Vector2 GetMousePosition();
	/// <summary>
	/// 判断指定鼠标按钮当前是否被按下
	/// </summary>
	/// <param name="button">要检测的鼠标按钮编号</param>
	/// <returns>如果指定的鼠标按钮被按下则返回true否则返回false</returns>
	static bool GetMouseButton(int button);
};
