#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class ClothesScene2 : public SceneBase
{
public:
	ClothesScene2();
	~ClothesScene2();
	void Update() override;
	void Draw() override;
private:
	std::vector<Button> buttons;
};
