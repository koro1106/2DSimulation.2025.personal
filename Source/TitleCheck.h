#pragma once
#include "Button.h"
/// <summary>
/// タイトルに戻る際の確認ウィンドウクラス
/// </summary>
class TitleCheck
{
public:
	TitleCheck();
	~TitleCheck();
	void Update();
	void Draw();
private:
	std::vector<Button> buttons;
	int fontHandl;
};