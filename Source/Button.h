#pragma once
#include <vector>
#include <functional>
#include <string> 
#include <cmath>    // fabs()用

class Button
{
public:
	// 画像一枚のボタン
	Button(int x, int y, int width, int height, const std::string& buttonID, int normalImage, std::function<void()> onClick = nullptr);
	// ホバー画像ありのボタン
	Button(int x, int y, int width, int height, const std::string& buttonID, int normalImage, int hoverImage, std::function<void()> onClick = nullptr);
	bool IsMouseOver(int mouseX, int mouseY)const;
	void OnClick()const;
	void Draw()const;
	static void ButtonSystem(std::vector<Button>& buttons);
	void SetAnimation(float tx, float ty, float speed = 0.4f);
	void UpdateAnimation();
	void SetAnimationStart(float startY);
	bool animFinished;
private:
	int x, y;
	int width, height;
	std::string buttonID;
	int normalImage; // 通常の画像
	int hoverImage = -1; // カーソルが重なった時の画像(デフォルトはなし)
	std::function<void()>onClickFunc; //ボタンがクリックされたときに実行される関数(関数を格納できる変数)
	// アニメーション用
	int targetX, targetY;
	int  originalX, originalY;
	float animSpeed ;
};