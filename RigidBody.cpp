// RigidBody.cpp
#include "RigidBody.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include <iostream>
#include <cmath>
#include <float.h>

void RigidBody::Start() {}

void RigidBody::Update(float deltaTime)
{
    velocity += acceleration * deltaTime;
    velocity *= pow(0.95f, deltaTime * 0.05);
    if (velocity.y > 0.2f)
    {
        velocity.y = 0.2f;
    }
    gameObject->transform.position += velocity * deltaTime;
    acceleration = {0, 0};
}
void RigidBody::AddForce(Vector2 force)
{
    acceleration += force;
}