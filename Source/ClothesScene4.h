#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class ClothesScene4 : public SceneBase
{
public:
	ClothesScene4();
	~ClothesScene4();
	void Update() override;
	void Draw() override;
private:
	std::vector<Button> buttons;
};
