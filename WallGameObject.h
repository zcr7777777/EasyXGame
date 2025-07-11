#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
#include "Graphics.h"
/// <summary>
/// «Ω±⁄”Œœ∑∂‘œÛ
/// </summary>
class WallGameObject : public GameObject
{
private:
    BoxCollider* boxCollider = nullptr;
public:
    WallGameObject(std::string name,int renderOrder,Transform transform);
    void Start() override;
    void UpdateLogic(float deltaTime) override;
};

