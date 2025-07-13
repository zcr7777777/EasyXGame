#include "Animator.h"
Animator::Animator(GameObject* obj) : IComponent(obj) {}
void Animator::Start(){
    textures.push_back(std::make_shared<IMAGE>());
    loadimage(textures[0].get(), _T("playerTexture1.png"));
    textures.push_back(std::make_shared<IMAGE>());
    loadimage(textures[1].get(), _T("playerTexture2.png"));
    textures.push_back(std::make_shared<IMAGE>());
    loadimage(textures[2].get(), _T("playerTexture3.png"));
    ChangeTexture(0);
}
void Animator::UpdateLogic(float deltaTime){
    timer+=deltaTime;
}
void Animator::ChangeTexture(int id){
    if(id<textures.size()&&id>=0){
        gameObject->texture=textures[id];
    }
}
Animator::~Animator() {
    textures.clear();
}