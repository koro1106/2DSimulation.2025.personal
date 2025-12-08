#include "ManualScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"

ManualScene::ManualScene()
{
	ImageManager::LoadAll();
	// Get the image handle
	int back = ImageManager::Get("back");

	buttons.emplace_back(500, 150, 120, 93, "SceneBack", back,[]() {
		OverlayManager::HideOverlay();
	});

	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 27, 0);
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
	// 背景
	DrawGraph(530, 150, ImageManager::Get("manualBG"), TRUE);
	//Button Drawing
	for (auto& button : buttons)
	{
		button.Draw();
	}

	DrawFormatStringToHandle(570, 290, GetColor(180, 180, 0), fontHandl, "【家庭用ロボット製造手順】");
	DrawFormatStringToHandle(580, 380, GetColor(180, 180, 0), fontHandl,"1:発注リストを確認");
	DrawFormatStringToHandle(580, 500, GetColor(180, 180, 0), fontHandl,"2:４つの装備を");
	DrawFormatStringToHandle(580, 540, GetColor(180, 180, 0), fontHandl,"　発注通りに組み合わせる");
	DrawFormatStringToHandle(580, 660, GetColor(180, 180, 0), fontHandl,"3:【次】へ行き評価をもらう");

}
