#include "Engine.h"
#include "windows.h"
#include "Render.h"
#include "BoxCollider.h"
#include <iostream>
#include <algorithm>
#include <chrono>
Engine* Engine::instance = nullptr;
bool Engine::isRunning = false;
Engine::Engine(Vector2 frameScale = {}) :frameScale(frameScale) {}
void Engine::Start() {
    std::cout << "C++ Version: " << __cplusplus << std::endl;
    isRunning = true;
    std::cout << "Engine Started" << std::endl;
    Render::Initialize(frameScale);
    ImmAssociateContext(Render::windowHandle, NULL);
    std::sort(gameObjects.begin(), gameObjects.end(), [](GameObject* a, GameObject* b) { return a->renderOrder < b->renderOrder; });
}
void Engine::AddGameObject(GameObject* obj) {
    gameObjects.push_back(obj);
    obj->Start();
}
void Engine::RunTime() {
    auto lastTime = std::chrono::high_resolution_clock::now();
    std::cout << "Engine Running" << std::endl;
    while (isRunning) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        float dt = deltaTime.count();
        Render::BeginFrame(1000.f / dt);
        for (GameObject* gameObject : gameObjects) {
            gameObject->Update(dt);   
        }
        Render::RenderGameObjects();
        Render::EndFrame();
    }
}
Engine* Engine::GetInstance(Vector2 frameScale = {}) {
    if (!instance) {
        instance = new Engine(frameScale);
    }
    return instance;
}
void Engine::Dispose() {
    std::cout << "Engine Disposed" << std::endl;
    if (instance) {
        for (auto gameObject : instance->gameObjects) {
            if (gameObject) {
                delete gameObject;
            }
            gameObject = nullptr;
        }
        BoxCollider::s_Instances.clear();
        delete instance;
    }
    instance = nullptr;
    Render::Dispose();
}