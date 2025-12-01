#pragma once
#include "../Library/SceneBase.h"
#include <vector> 
#include "Button.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
private:
	int mouseX, mouseY;
	bool prevButton; 
	int fontHandl;
	std::vector<Button> buttons;
	float t = 0.0f;
	float gearAngle = 0.0f; // 歯車回転速度
	int mx, my;// マウス位置
};
