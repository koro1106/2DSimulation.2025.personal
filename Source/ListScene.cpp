#include "ListScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"

ListScene::ListScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int back = ImageManager::Get("back");
	 
	buttons.emplace_back(590, 90, 120, 93, "Back", back, []() {
		OverlayManager::HideOverlay();
		});
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
	DrawGraph(650, 110, ImageManager::Get("listScene"), TRUE);

	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}