#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 

class ClothesScene3 : public SceneBase
{
public:
	ClothesScene3();
	~ClothesScene3();
	void Update() override;
	void Draw() override;
	bool isInitialized = false; // ‰Šú‰»‚³‚ê‚½‚©
private:
	std::vector<Button> buttons;
	int fontHandl;
};
