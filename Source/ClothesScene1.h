#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class ClothesScene1 : public SceneBase
{
public:
	ClothesScene1();
	~ClothesScene1();
	void Update() override;
	void Draw() override;
private:
	std::vector<Button> buttons;
};