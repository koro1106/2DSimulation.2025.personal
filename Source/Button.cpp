#include "Button.h"
#include "CSVManager.h"
#include "../Library/SceneBase.h"
#include "ImageManager.h"
#include "OverlayAnimation.h"

// 画像一枚のボタン
Button::Button(int x, int y, int width, int height, const std::string& buttonID, int normalImage, std::function<void()> onClick)
	: x(x), y(y), width(width), height(height),buttonID(buttonID),normalImage(normalImage), hoverImage(-1), onClickFunc(onClick)
{
	// アニメーションの最終位置（本来の位置）記録
	originalX = x;
	originalY = y;
}

// ホバー画像ありのボタン
Button::Button(int x, int y, int width, int height, const std::string& buttonID, int normalImage, int hoverImage,const std::function<void()> onClick)
	: x(x), y(y), width(width), height(height), buttonID(buttonID), normalImage(normalImage), hoverImage(hoverImage), onClickFunc(onClick)
{}

bool Button::IsMouseOver(int mouseX, int mouseY) const
{
    return mouseX >= x && mouseX <= x + width &&
           mouseY >= y && mouseY <= y + height;
}

void Button::OnClick() const
{
	if (onClickFunc) // もし関数がセットされていれば
	{
		onClickFunc(); // その関数呼ぶ
	}
	else
	{
		//CSVにしたがってシーン変える
		std::string currentScene = SceneManager::GetCurrentSceneName();
		std::string nextScene = CSVManager::GetNextScene(currentScene, this->buttonID);
		if (!nextScene.empty()) 
		{
			CSVManager::ChangeScene(nextScene);
		}
	}
}

void Button::Draw() const
{
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);

	// カーソルが上に乗っているかで画像分ける
	int image = (hoverImage != -1 && IsMouseOver(mouseX, mouseY)) ? hoverImage : normalImage;

	DrawGraph(x, y, image, TRUE);
}

void Button::ButtonSystem(std::vector<Button>& buttons)
{
	static bool prevButton = false;
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	bool isMousePressed = (GetMouseInput() & MOUSE_INPUT_LEFT);

	//Button
	for (auto& button : buttons)
	{
		// マウスがボタンの上にあるか
		if (button.IsMouseOver(mouseX, mouseY))
		{
			//　押された瞬間だけクリック扱い
			if (isMousePressed && !prevButton)
			{
				button.OnClick();
			}
		}
	}
	//　前の状態記録
	prevButton = isMousePressed;
}
// アニメーション開始
void Button::SetAnimation(float tx, float ty, float speed)
{
	targetX = tx;
	targetY = ty;
	animSpeed = speed;
	animFinished = false;
}
// アニメーション更新
void Button::UpdateAnimation()
{
	if (animFinished) return;

	x += (targetX - x) * animSpeed;
	y += (targetY - y) * animSpeed;

	if (fabs(targetX - x) < 1 && fabs(targetY - y) < 1)
	{
		x = targetX;
		y = targetY;
		animFinished = true; //アニメーション終了
	}
}

// アニメーションする際の最初のY座標
void Button::SetAnimationStart(float startY)
{
	y = startY;             // 初期位置を強制セット
	targetX = originalX;
	targetY = originalY;
	animSpeed = 0.4f;
	animFinished = false;
}

