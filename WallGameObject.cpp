#include "WallGameObject.h"
#include "Graphics.h"
#include "FloorMoving.h"
WallGameObject::WallGameObject(std::string name,int renderOrder, Transform transform):GameObject(name,GameObjectType::Floor,renderOrder){
    this->transform = transform;
    texture = new IMAGE();
}
void WallGameObject::Start()
{
    loadimage(texture, _T("floorTexture.bmp"));
    BoxCollider* boxCollider = new BoxCollider(this);
    boxCollider->size = transform.scale;
    AddComponent(boxCollider);
}
void WallGameObject::UpdateLogic(float deltaTime) {
    for (auto component : components)
        component->UpdateLogic(deltaTime);
}