#include "Button.h"
#include "CSVManager.h"
#include "../Library/SceneBase.h"
#include "ImageManager.h"
#include "OverlayAnimation.h"

Button::Button(int x, int y, int width, int height, const std::string& buttonID, int imageHandle,const std::function<void()> onClick)
	: x(x), y(y), width(width), height(height), buttonID(buttonID), imageHandle(imageHandle), onClickFunc(onClick) {}

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
	if (imageHandle != -1)
	{
		DrawGraph(x, y, imageHandle, TRUE);
	}
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
