#pragma once
#include "GameObject.h"
class PictureGameObject : public GameObject
{
public:
    PictureGameObject(std::string name,int renderOrder,Vector2 pos, std::string picturePath) :GameObject(name, GameObject::GameObjectType::Other, renderOrder) {
        transform = Transform(pos, Vector2(1, 1), 0);
        texture = new IMAGE();
        std::wstring path= std::wstring(picturePath.begin(), picturePath.end());
        loadimage(texture, path.c_str());
    }
	void Start() override;
    void UpdateLogic(float deltaTime) override;
    ~PictureGameObject() override= default;
};

