#include "Button.h"
#include "CSVManager.h"
#include "../Library/SceneBase.h"
#include "ImageManager.h"

Button::Button(int x, int y, int width, int height, const std::string& buttonID, int imageHandle)
	: x(x), y(y), width(width), height(height), buttonID(buttonID), imageHandle(imageHandle) {}

bool Button::IsMouseOver(int mouseX, int mouseY) const
{
    return mouseX >= x && mouseX <= x + width &&
           mouseY >= y && mouseY <= y + height;
}

void Button::OnClick() const
{
    std::string currentScene = SceneManager::GetCurrentSceneName();
    std::string nextScene = CSVManager::GetNextScene(currentScene, this->buttonID);
    if (!nextScene.empty()) {
        CSVManager::ChangeScene(nextScene);
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
		if (button.IsMouseOver(mouseX, mouseY))
		{
			//Click Only
			if (isMousePressed && !prevButton)
			{
				button.OnClick();
			}
		}
	}
	//Save the previous input
	prevButton = isMousePressed;
}
