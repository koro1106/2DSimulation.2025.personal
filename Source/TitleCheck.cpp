#include "ResultCheck.h"
#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"

TitleCheck::TitleCheck()
{
	ImageManager::LoadAll();
	int back = ImageManager::Get("back");
	int yes = ImageManager::Get("yes");

	buttons.emplace_back(430, 260, 120, 93, "SceneBack", back, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(810, 610, 217, 74, "Yes", yes, []() {
		OverlayManager::ShowOverlay("RESULT");
		});
	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 45, 0);
}

TitleCheck::~TitleCheck()
{
}
void TitleCheck::Update()
{
	Button::ButtonSystem(buttons);//Button System
}
void TitleCheck::Draw()
{
	DrawGraph(450, 260, ImageManager::Get("checkBG"), TRUE);
	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	DrawFormatStringToHandle(630, 450, GetColor(180, 180, 0), fontHandl, "%s", "業務を終了しますか？");

}