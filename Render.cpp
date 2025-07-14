#include "Render.h"
#include <graphics.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>
namespace Render { 
	HWND windowHandle = nullptr;
	std::vector<std::function<void()>> UIRender;
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
	BeginBatchDraw();
}
void Render::RenderGameObjects() {
	for (auto gameObject : Engine::GetInstance({})->gameObjects) {
		RenderGameObject(gameObject);
	}
	for (auto uiRender : UIRender) {
		uiRender();
	}
}

void Render::AddUIRender(std::function<void()> func) {
    UIRender.push_back(func);
}

void putimage_alpha(IMAGE* dstImg, int x, int y, IMAGE* srcImg, UINT transparentColor)
{
	HDC dstDC = GetImageHDC(dstImg);
	HDC srcDC = GetImageHDC(srcImg);
	int w = srcImg->getwidth();
	int h = srcImg->getheight();
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentColor);
}
void Render::RenderGameObject(GameObject* gameObject) {
	if (gameObject->texture != nullptr) {
		Transform transform = gameObject->transform;
		putimage_alpha(NULL, -transform.scale.x / 2.0 + transform.position.x, -transform.scale.y / 2.0 + transform.position.y, gameObject->texture.get(), WHITE);
	}
}
void Render::EndFrame() {
	FlushBatchDraw();
	EndBatchDraw();
}
void Render::Dispose() {
	UIRender.clear();
	closegraph();
}