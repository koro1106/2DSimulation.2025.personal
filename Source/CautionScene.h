#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class CautionScene : public SceneBase
{
public:
	CautionScene();
	~CautionScene();
	void Update() override;
	void Draw() override;
private:
	std::vector<Button> buttons;
};