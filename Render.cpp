#include "Render.h"
#include <graphics.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>
namespace Render { 
	HWND windowHandle = nullptr;
}
void Render::Initialize(Vector2 frameScale) {
	windowHandle = initgraph(frameScale.x, frameScale.y, EW_SHOWCONSOLE);
	setbkmode(TRANSPARENT);
	setbkcolor(WHITE);
}
void Render::BeginFrame(float fps) {
	std::string fpsString = "EasyX Game FPS: " + std::to_string(fps);
	std::wstring windowTitle = std::wstring(fpsString.begin(), fpsString.end());
	SetWindowText(windowHandle, windowTitle.c_str());
	cleardevice();
	BeginBatchDraw();
}
void Render::RenderGameObjects() {
	for (auto gameObject : Engine::GetInstance({})->gameObjects) {
		RenderGameObject(gameObject);
	}
}
void Render::RenderGameObject(GameObject* gameObject) {
	if (gameObject->texture != nullptr) {
		Transform transform = gameObject->transform;
		putimage(-transform.scale.x / 2.0 + transform.position.x, -transform.scale.y / 2.0 + transform.position.y,gameObject-> texture);
	}
}
void Render::EndFrame() {
	FlushBatchDraw();
	EndBatchDraw();
}
void Render::Dispose() {
	closegraph();
}