#pragma once
#include "Button.h"

class ResultCheck
{
public:
	ResultCheck();
	~ResultCheck();
	void Update();
	void Draw();
	void ScaleAnimation(); // 拡大アニメーション
private:
	std::vector<Button> buttons;
	int fontHandl;
	// アニメーション
	int centerX, centerY; // 中心座標
	int newWidth, newHeight; // 新しい幅と高さ
	int drawX, drawY; // 描画位置
	int imageWidth, imageHeight; // 画像の幅と高さ
	float scale = 1.0f;    // 拡大率
	float scaleSpeed = 0.06f; // 拡大速度
};
