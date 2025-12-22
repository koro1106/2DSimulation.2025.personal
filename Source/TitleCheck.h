#pragma once
#include "Button.h"
#include "ResultCheck.h"

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
	void ScaleAnimation(); // 拡大アニメーション
private:
	std::vector<Button> buttons;
	int fontHandl;
	// アニメーション用
	ResultCheck resultCheck;
	int imageWidth, imageHeight; // 画像の幅と高さ
	int newWidth, newHeight; // 新しい幅と高さ
	int drawX, drawY; // 描画位置
	float scale = 1.0f;    // 拡大率
	float scaleSpeed = 0.03f; // 拡大速度

};