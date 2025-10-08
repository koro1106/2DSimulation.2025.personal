#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
private:
	bool prevButton;
	int mouseX, mouseY;
	std::vector<Button> buttons;
};