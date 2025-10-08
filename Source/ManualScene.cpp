#include "ManualScene.h"
#include "ImageManager.h"

ManualScene::ManualScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int back = ImageManager::Get("back");

	buttons.emplace_back(700, 250, 120, 93, "Back", back);
}

ManualScene::~ManualScene()
{
}

void ManualScene::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void ManualScene::Draw()
{
	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}
