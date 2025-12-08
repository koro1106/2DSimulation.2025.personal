#include "ListScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "OrdersCSVManager.h"
#include <iostream>

ListScene::ListScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int back = ImageManager::Get("back");
	 
	buttons.emplace_back(500, 190, 120, 93, "SceneBack", back, []() {
		OverlayManager::HideOverlay();
		});
	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 30, 0);
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
	DrawGraph(530, 200, ImageManager::Get("listBG"), TRUE);

	if (!OrdersCSVManager::orders.empty())
	{
		const auto& row = OrdersCSVManager::orders[0]; // 1行目

		DrawFormatStringToHandle(650, 370, GetColor(0, 0, 0), fontHandl, "%s", row.order1.c_str());
		DrawFormatStringToHandle(650, 450, GetColor(0, 0, 0), fontHandl, "%s", row.order2.c_str());
		DrawFormatStringToHandle(650, 480, GetColor(0, 0, 0), fontHandl, "%s", row.order3.c_str());
		DrawFormatStringToHandle(650, 560, GetColor(0, 0, 0), fontHandl, "%s", row.order4.c_str());
	}
	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}