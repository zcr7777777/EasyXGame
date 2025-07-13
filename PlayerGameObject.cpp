#include "PlayerGameObject.h"
#include "graphics.h"
#include "Input.h"
#include "IComponent.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "Animator.h"
#include "Engine.h"
#include <functional>
#include <iostream>
#ifndef VK_A
#define VK_A 0x41
#endif
#ifndef VK_D
#define VK_D 0x44
#endif

void PlayerGameObject::Start(){
    transform.scale=Vector2{ 80,80 };
    rigidBody = new RigidBody(this);
    boxCollider = new BoxCollider(this);
    animator = new Animator(this);
    audioSource = new AudioSource(this);
    AddComponent(boxCollider);
    AddComponent(rigidBody);
    AddComponent(animator);
    AddComponent(audioSource);
    boxCollider->onCollisionEnter = std::bind(&PlayerGameObject::OnCollisionEnter, this, std::placeholders::_1);
    boxCollider->onCollisionStay = std::bind(&PlayerGameObject::OnCollisionStay, this, std::placeholders::_1);
    boxCollider->onCollisionExit = std::bind(&PlayerGameObject::OnCollisionExit, this, std::placeholders::_1);
    boxCollider->onTriggerEnter = std::bind(&PlayerGameObject::OnTriggerEnter, this, std::placeholders::_1);
    rigidBody->velocity = {0.2f,0.1f};
    for (auto component : components) {
        component->Start();
    }
}
void PlayerGameObject::OnCollisionEnter(GameObject* other) {
    animator->ChangeTexture(2);
    std::cout <<name << " Collision Enter with " << other->name << std::endl;
    if (rigidBody->velocity.y > 0 && !(((transform.position.x < other->transform.position.x - other->transform.scale.x / 2 + 1) || (transform.position.x > other->transform.position.x + other->transform.scale.x / 2 - 1)) && (transform.position.y + transform.scale.y / 2 > other->transform.position.y - other->transform.scale.y / 2 + 10))) {
        onGround = true;
        canJump = true;
    }
    rigidBody->velocity = rigidBody->velocity.Length() > 0.1 ? -rigidBody->velocity * 0.3f : Vector2(0, 0);
}
void PlayerGameObject::OnCollisionStay(GameObject* other) {
    animator->ChangeTexture(2);
    if (((transform.position.x < other->transform.position.x - other->transform.scale.x / 2 + 1) || (transform.position.x > other->transform.position.x + other->transform.scale.x / 2 - 1)) && (transform.position.y + transform.scale.y / 2 > other->transform.position.y - other->transform.scale.y / 2 + 10)) {
        if (transform.position.x < other->transform.position.x) {
            rigidBody->velocity.x = min(other->GetComponent<RigidBody>()->velocity.x,rigidBody->velocity.x);
        }
        else {
            rigidBody->velocity.x = max(other->GetComponent<RigidBody>()->velocity.x,rigidBody->velocity.x);
        }
        if (sideCollider.find(other) == sideCollider.end()) {
            sideCollider.insert(other);
        }
    }
    else{
        onGround = true;
        if (groundCollider.find(other) == groundCollider.end()) {
            groundCollider.insert(other);
        }
        if (sideCollider.empty()) {
            rigidBody->velocity.x += other->GetComponent<RigidBody>()->velocity.x * 1.3;
        }
    }
    std::cout << name << " Collision Stay  with " << other->name <<std::endl;
}
void PlayerGameObject::OnCollisionExit(GameObject* other) {
    std::cout << name << " Collision Exit  with " << other->name << std::endl;
    auto it=sideCollider.find(other);
    if (it != sideCollider.end()) {
        sideCollider.erase(it);
    }
    it = groundCollider.find(other);
    if (it != groundCollider.end()) {
        groundCollider.erase(it);
    }
    if (groundCollider.empty()) {
        onGround = false;
    }
}
void PlayerGameObject::UpdateLogic(float deltaTime) {
    if (groundCollider.empty()) {
        onGround=false;
    }
    if (abs(rigidBody->velocity.y) > 0.05f)
        animator->ChangeTexture(0);
    if(Input::GetMouseButton(0)&&
        Input::GetMousePosition().x>= -transform.scale.x / 2.0 + transform.position.x &&
        Input::GetMousePosition().x <= transform.scale.x / 2.0 + transform.position.x &&
        Input::GetMousePosition().y >= -transform.scale.y / 2.0 + transform.position.y &&
        Input::GetMousePosition().y <= transform.scale.y / 2.0 + transform.position.y&&
        canJump) {
        audioSource->Play("clickAudio.wav");
        rigidBody->velocity.y = -1;
        canJump = false;
    }
    if (!onGround) {
        rigidBody->AddForce({0,0.001f});
    }
    if(Input::GetKey(VK_A)){
        rigidBody->velocity = { -0.2f,rigidBody->velocity.y };
    }else if (Input::GetKey(VK_D)) {
        rigidBody->velocity = { 0.2f,rigidBody->velocity.y };
    }
    else {
        rigidBody->velocity = { 0,rigidBody->velocity.y };
    }
    Vector2 frameScale = Engine::GetInstance({})->frameScale;
    for (auto component : components) {
        component->UpdateLogic(deltaTime);
    }
    if (transform.position.y > frameScale.y - transform.scale.y / 2) {
        transform.position = { 0,0 };
        sideCollider.clear();
        groundCollider.clear();
    }
    if (transform.position.x > frameScale.x-transform.scale.x/2) {
        transform.position.x = frameScale.x - transform.scale.x / 2;
    }else if (transform.position.x < transform.scale.x / 2) {
        transform.position.x = transform.scale.x / 2;
    }
    if (transform.position.y < transform.scale.y / 2) {
        transform.position.y = transform.scale.y / 2;
    }
}
PlayerGameObject::PlayerGameObject(std::string name,int renderOrder,Vector2 pos):GameObject(name,GameObjectType::Player,renderOrder){
    transform.position = pos;
}

void PlayerGameObject::OnTriggerEnter(GameObject* other) {
    std::cout << name << " Trigger Enter with " << other->name << std::endl;
    Engine::GetInstance({})->isRunning = false;
}