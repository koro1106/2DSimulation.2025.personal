#include "ListScene.h"
#include "ImageManager.h"

ListScene::ListScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int back = ImageManager::Get("back");
	 
	buttons.emplace_back(700, 250, 120, 93, "Back", back);
}

ListScene::~ListScene()
{
}

void ListScene::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void ListScene::Draw()
{
	DrawGraph(0, 0, ImageManager::Get("listBg"), TRUE);

	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}