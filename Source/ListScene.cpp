#include "ListScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "OrdersCSVManager.h"
#include <iostream>
#include "SoundManager.h"

ListScene::ListScene()
{
	// Get the image handle
	int back = ImageManager::Get("back");
	 
	buttons.emplace_back(500, 200, 120, 93, "SceneBack", back, []() {
		OverlayManager::HideOverlay();
		SoundManager::PlaySE("clickBack");
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

	if (openAmount < 1.0f) {
		openAmount += 0.06f;  //少しづつ表示 
	}
}

void ListScene::Draw()
{

	int img = ImageManager::Get("listBG");
	int w, h;
	GetGraphSize(img, &w, &h);

	// 上端の固定座標
	int topX = 540;
	int topY = 200;

	float scale = openAmount; // 0:見えない、1:全表示

	// 下端の座標を scale に応じて計算
	int bottomX = topX + w;
	int bottomY = topY + (int)(h * scale);

	// 伸縮描画
	DrawExtendGraph(topX, topY, bottomX, bottomY, img, TRUE);

	// 発注リストタイトル描画
	DrawGraph(820, 180, ImageManager::Get("listTitle"), TRUE);

	// CSVの発注内容描画
	if (!OrdersCSVManager::orders.empty())
	{
		int idx = OrdersCSVManager::currentOrderIndex;
		const auto& row = OrdersCSVManager::orders[idx]; // idx行目

		DrawFormatStringToHandle(600, 370, GetColor(0, 0, 0), fontHandl, "%s", row.order1.c_str());
		DrawFormatStringToHandle(600, 450, GetColor(0, 0, 0), fontHandl, "%s", row.order2.c_str());
		DrawFormatStringToHandle(600, 480, GetColor(0, 0, 0), fontHandl, "%s", row.order3.c_str());
		DrawFormatStringToHandle(600, 560, GetColor(0, 0, 0), fontHandl, "%s", row.order4.c_str());
	}
	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}