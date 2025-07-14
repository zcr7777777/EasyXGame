#include "WallGameObject.h"
#include "Graphics.h"
#include "FloorMoving.h"
WallGameObject::WallGameObject(std::string name,int renderOrder, Transform transform):GameObject(name,GameObjectType::Floor,renderOrder){
    this->transform = transform;
    texture = std::make_shared<IMAGE>();
}
void WallGameObject::Start()
{
    loadimage(texture.get(), _T("floorTexture.bmp"));
    BoxCollider* boxCollider = new BoxCollider(this);
    boxCollider->size = transform.scale;
    rigidBody = new RigidBody(this);
    rigidBody->acceleration = { 0,0 };
    AddComponent(rigidBody);
    AddComponent(boxCollider);
}
void WallGameObject::Update(float deltaTime) {
    for (auto component : components)
        component->UpdateLogic(deltaTime);
}