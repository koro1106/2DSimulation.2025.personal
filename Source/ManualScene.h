#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class ManualScene : public SceneBase
{
public:
	ManualScene();
	~ManualScene();
	void Update() override;
	void Draw() override;
private:
	std::vector<Button> buttons;
};