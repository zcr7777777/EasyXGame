#pragma once
#include "Input.h"
#include "Render.h"
#include <windows.h>
#include <graphics.h>

Vector2 Input::GetMousePosition() {
    // 获取屏幕坐标
    POINT point;
    GetCursorPos(&point);

    // 转换为窗口客户区坐标
    HWND hWnd = Render::windowHandle; // EasyX 维护的窗口句柄
    ScreenToClient(hWnd, &point);

    // 返回 Vector2 结构体
    return Vector2(static_cast<float>(point.x), static_cast<float>(point.y));
}

bool Input::GetKey(int keyCode) {
    return GetAsyncKeyState(keyCode) != 0;
}

bool Input::GetMouseButton(int button) {
    int vkCode = 0;
    switch (button) {
    case 0: vkCode = VK_LBUTTON; break; // 左键
    case 1: vkCode = VK_RBUTTON; break; // 右键
    case 2: vkCode = VK_MBUTTON; break; // 中键
    default: return false; // 无效按钮编号
    }

    // 检测按键状态（使用位掩码检查最高位）
    return (GetAsyncKeyState(vkCode) & 0x8000) != 0;
}