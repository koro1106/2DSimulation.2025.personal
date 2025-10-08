#include "ClothesScene2.h"
#include "ImageManager.h"

ClothesScene2::ClothesScene2()
{
	ImageManager::LoadAll();
	// Get the image handle
	int clothesBack = ImageManager::Get("back");
	int back = ImageManager::Get("-1");
	int next = ImageManager::Get("+1");

	buttons.emplace_back(20, 20, 120, 93, "SceneBack", clothesBack);
	buttons.emplace_back(0, 870, 210, 210, "Back", back);
	buttons.emplace_back(1715, 870, 210, 210, "Next", next);
}

ClothesScene2::~ClothesScene2()
{
}

void ClothesScene2::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void ClothesScene2::Draw()
{
	DrawGraph(0, 0, ImageManager::Get("defense"), TRUE);

	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}
