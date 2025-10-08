#include "PlayScene.h"
#include "ImageManager.h"

PlayScene::PlayScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int bg4Image = ImageManager::Get("bg4");
	int list = ImageManager::Get("list");
	int hatena = ImageManager::Get("hatena");
	int book = ImageManager::Get("book");
	int door = ImageManager::Get("door");
	int exit = ImageManager::Get("exit");

	buttons.emplace_back(50, 250, 400, 780, "Clothes", bg4Image);
	buttons.emplace_back(50, 70, 120, 137, "Manual", hatena);
	buttons.emplace_back(190, 80, 120, 120, "List", list);
	buttons.emplace_back(335, 75, 110, 147, "Caution", book);

	buttons.emplace_back(1830, 5, 82, 130, "Title", door);
	buttons.emplace_back(1550, 850, 280, 174, "Exit", exit);
}

PlayScene::~PlayScene()
{
}
void PlayScene::Update()
{
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
void PlayScene::Draw()
{
	//BackGround
	DrawGraph(0, 0, ImageManager::Get("bg1"), TRUE);
	DrawGraph(490, 0, ImageManager::Get("bg2"), TRUE);
	DrawGraph(950, 170, ImageManager::Get("human"), TRUE);

	//UI
	DrawGraph(1800, 300, ImageManager::Get("meter"), TRUE);

	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}
