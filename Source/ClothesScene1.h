#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 
#include "OverlayAnimation.h"

class ClothesScene1 : public SceneBase
{
public:
	ClothesScene1();
	~ClothesScene1();
	void Update() override;
	void Draw() override;
	bool isInitialized = false; // èâä˙âªÇ≥ÇÍÇΩÇ©
private:
	std::vector<Button> buttons;
	std::string Utf8ToSjis(const std::string& src);
	OverlayAnimation overlayAnim;
	int fontHandl;
};