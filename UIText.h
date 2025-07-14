#pragma once
#include "GameObject.h"
#include "Render.h"
class UIText : public GameObject
{
public:
	void drawText(int x, int y, std::wstring s);
	std::wstring text;
    UIText(std::string name, int renderOrder, Vector2 pos, std::wstring text) :GameObject(name, GameObject::GameObjectType::Other, renderOrder)
    {
        this->text = text;
        transform = Transform(pos, Vector2(1, 1), 0);
    }
    void Start() override;
    void Update(float deltaTime) override {}
};

