#include "ListScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "OrdersCSVManager.h"
#include <iostream>
#include "SoundManager.h"

ListScene::ListScene()
{
	// 画像ハンドル取得
	int back = ImageManager::Get("back");
	 
	buttons.emplace_back(500, 200, 120, 93, "SceneBack", back, []() {
		OverlayManager::HideOverlay();
		SoundManager::PlaySE("clickBack");
		});
	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 30, 0);

	SetOrderText();
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

	// 上から順番に表示
	for (int i = 0; i < 4; i++)
	{
		if (!orderMessages[i].IsFinished())
		{
			orderMessages[i].Update();
			break; // 1つずつ
		}
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
	int x = 600;
	int y = 370;
	int lineSpace = 80; // 行スペース

	for (int i = 0; i < 4; i++)
	{
		orderMessages[i].Draw(x,y + i * lineSpace,GetColor(0, 0, 0),fontHandl);
	}

	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}
}

// CSV内容を1つの文字列にまとめる
void ListScene::SetOrderText()
{
	if (OrdersCSVManager::orders.empty()) return;


	int idx = OrdersCSVManager::currentOrderIndex;
	const auto& row = OrdersCSVManager::orders[idx]; // idx行目

	orderMessages[0].SetText(row.order1);
	orderMessages[1].SetText(row.order2);
	orderMessages[2].SetText(row.order3);
	orderMessages[3].SetText(row.order4);
}
