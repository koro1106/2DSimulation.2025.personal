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

	DrawFormatStringToHandle(570, 350, GetColor(180, 160, 0), fontHandl, "【家庭用ロボット製造手順】");
	DrawFormatStringToHandle(580, 420, GetColor(180, 160, 0), fontHandl,"1:発注リストを確認");
	DrawFormatStringToHandle(580, 540, GetColor(180, 160, 0), fontHandl,"2:４つの装備を");
	DrawFormatStringToHandle(580, 580, GetColor(180, 160, 0), fontHandl,"　発注通りに組み合わせる");
	DrawFormatStringToHandle(580, 690, GetColor(180, 160, 0), fontHandl,"3:【次】へ行き評価をもらう");
	DrawFormatStringToHandle(990, 420, GetColor(180, 160, 0), fontHandl,"4:評価は4段階");
	DrawFormatStringToHandle(990, 460, GetColor(180, 160, 0), fontHandl,"  (Perfect/Great/Nice/Miss)");
	DrawFormatStringToHandle(990, 540, GetColor(180, 160, 0), fontHandl,"5:Great以上なら");
	DrawFormatStringToHandle(990, 580, GetColor(180, 160, 0), fontHandl,"  次の業務へ進むことができる");
	DrawFormatStringToHandle(990, 690, GetColor(180, 160, 0), fontHandl,"6:Great以下ならやり直し");

}
