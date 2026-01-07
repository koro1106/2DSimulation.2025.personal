#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 
#include "Message.h"

class ListScene : public SceneBase
{
public:
	ListScene();
	~ListScene();
	void Update() override;
	void Draw() override;
	void SetOrderText();
private:
	std::vector<Button> buttons;
	int fontHandl;
	// アニメーション用
	float openAmount = 0.0f; // 初期状態
	Message orderMessages[4];
};