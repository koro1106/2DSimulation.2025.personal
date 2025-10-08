#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
private:
	int TitleImage;
	int buttonX = 144;//button_X
	int buttonY = 644;//button_Y
	int buttonWidth = 440;//button_Width
	int buttonHeight = 140;//button_Height
	int mouseX, mouseY;
	bool prevButton; 
};
