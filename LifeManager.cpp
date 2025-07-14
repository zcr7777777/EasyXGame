#include "LifeManager.h"
void LifeManager::Start(){
	leftTime = 30000;
}
void LifeManager::Update(float deltaTime){
	if (win) {
        showWinTime -= deltaTime;
	}
	leftTime -= deltaTime;
	if (leftTime <= 0) {
		win = true;
		Engine::GetInstance({})->AddGameObjectInRun(new PictureGameObject("win",10,{40,40},"win.png"));
		Engine::GetInstance({})->AddGameObjectInRun(new UIText("thanks", 11, {700,200},_T("恭喜通关，感谢游玩！")));

	}
	if (showWinTime <= 0) {
		Engine::GetInstance({})->isRunning = false;
	}
}