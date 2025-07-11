#pragma once
#include "Input.h"
#include "Render.h"
#include <windows.h>
#include <graphics.h>

Vector2 Input::GetMousePosition() {
    // ��ȡ��Ļ����
    POINT point;
    GetCursorPos(&point);

    // ת��Ϊ���ڿͻ�������
    HWND hWnd = Render::windowHandle; // EasyX ά���Ĵ��ھ��
    ScreenToClient(hWnd, &point);

    // ���� Vector2 �ṹ��
    return Vector2(static_cast<float>(point.x), static_cast<float>(point.y));
}

bool Input::GetKey(int keyCode) {
    return GetAsyncKeyState(keyCode) != 0;
}

bool Input::GetMouseButton(int button) {
    int vkCode = 0;
    switch (button) {
    case 0: vkCode = VK_LBUTTON; break; // ���
    case 1: vkCode = VK_RBUTTON; break; // �Ҽ�
    case 2: vkCode = VK_MBUTTON; break; // �м�
    default: return false; // ��Ч��ť���
    }

    // ��ⰴ��״̬��ʹ��λ���������λ��
    return (GetAsyncKeyState(vkCode) & 0x8000) != 0;
}