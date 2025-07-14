#include "PictureGameObject.h"
void PictureGameObject::Start(){
    for (auto component : components) {
        component->Start();
    }
}
void PictureGameObject::Update(float deltaTime){
    for (auto component : components) {
        component->Update(deltaTime);
    }
}