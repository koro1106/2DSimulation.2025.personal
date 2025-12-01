#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class ListScene : public SceneBase
{
public:
	ListScene();
	~ListScene();
	void Update() override;
	void Draw() override;
private:
	std::vector<Button> buttons;
	int fontHandl;
};