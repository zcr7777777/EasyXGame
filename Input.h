#pragma once
#include "Transform.h"
/// <summary>
/// �����࣬��װ������Ҫ��������Ϣ
/// </summary>
class Input
{
public:
	/// <summary>
	/// �ж�ָ���İ����Ƿ񱻰��¡�
	/// </summary>
	/// <param name="key">Ҫ���İ����ļ���</param>
	/// <returns>��������������򷵻�true���򷵻�false</returns>
	static bool GetKey(int key);
	/// <summary>
	/// ��ȡ���ĵ�ǰλ��
	/// </summary>
	/// <returns>��ʾ��굱ǰλ�õ� Vector2 ����</returns>
	static Vector2 GetMousePosition();
	/// <summary>
	/// �ж�ָ����갴ť��ǰ�Ƿ񱻰���
	/// </summary>
	/// <param name="button">Ҫ������갴ť���</param>
	/// <returns>���ָ������갴ť�������򷵻�true���򷵻�false</returns>
	static bool GetMouseButton(int button);
};
