#include "CautionScene.h"
#include "ImageManager.h"

CautionScene::CautionScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int back = ImageManager::Get("back");

	buttons.emplace_back(700, 250, 120, 93, "Back", back);
}

CautionScene::~CautionScene()
{
}

void CautionScene::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void CautionScene::Draw()
{
	//ƒ{ƒ^ƒ“•`‰æ
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}
