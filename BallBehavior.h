#pragma once
#include "IComponent.h"
#include "RigidBody.h"
class BallBehavior : public IComponent
{
public:
    GameObject *owner;
    Vector2 v = {0, 0};
    void StartShoot(Vector2 startPos, Vector2 endPos);
    void Start() override;
    void Update(float deltaTime) override;
    ~BallBehavior() = default;
    BallBehavior(GameObject *obj, GameObject *owner) : IComponent(obj), owner(owner) {}
};
