#pragma once
#include "GameObject.h"
class PictureGameObject : public GameObject
{
public:
    PictureGameObject(std::string name,int renderOrder,Vector2 pos, std::string picturePath) :GameObject(name, GameObject::GameObjectType::Other, renderOrder) {
        transform = Transform(pos, Vector2(80,80), 0);
        texture = std::make_shared<IMAGE>();
        std::wstring path= std::wstring(picturePath.begin(), picturePath.end());
        loadimage(texture.get(), path.c_str());
    }
	void Start() override;
    void Update(float deltaTime) override;
    ~PictureGameObject() override= default;
};

