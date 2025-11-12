#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 
#include "OverlayAnimation.h"
#include "Light.h"

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	int mx, my;// マウス位置
private:
	bool prevButton;
	int mouseX, mouseY;
	std::vector<Button> buttons;
	OverlayAnimation overlayAnim;
	Light light1;
	Light light2;
	Light light3;
};