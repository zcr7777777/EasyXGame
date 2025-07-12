#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
#include "Graphics.h"
#include "RigidBody.h"
/// <summary>
/// «Ω±⁄”Œœ∑∂‘œÛ
/// </summary>
class WallGameObject : public GameObject
{
private:
    BoxCollider* boxCollider = nullptr;
    RigidBody* rigidBody = nullptr;
public:
    WallGameObject(std::string name,int renderOrder,Transform transform);
    void Start() override;
    void UpdateLogic(float deltaTime) override;
    ~WallGameObject() override=default;
};

