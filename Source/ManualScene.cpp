#include "ManualScene.h"
#include "ImageManager.h"
#include "SoundManager.h"
#include "OverlayManager.h"

ManualScene::ManualScene()
{
	// 画像ハンドル取得
	int back = ImageManager::Get("back");

	buttons.emplace_back(500, 150, 120, 93, "SceneBack", back,[]() {
		OverlayManager::HideOverlay();
		SoundManager::PlaySE("clickBack");

	});

	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 27, 0);

	// 全文セット
	messageLeft.SetText( // 左側
		"【家庭用ロボット製造手順】\n"
		"\n"
		"\n"
		"\n"
		"1:発注リストを確認\n"
		"\n"
		"\n"
		"\n"
		"2:４つの装備を\n"
		"　発注通りに組み合わせる\n"
		"\n"
		"\n"
		"\n"
		"3:【次】へ行き評価をもらう\n"
	);
	messageRight.SetText( // 右側
		"\n"
		"\n"
		"\n"
		"4:評価は4段階\n"
		" (Perfect/Great/Nice/Miss)\n"
		"\n"
		"\n"
		"\n"
		"5:Great以上なら\n"
		" 次の業務へ進むことができる\n"
		"\n"
		"\n"
		"\n"
		"6:Great以下ならやり直し"
	);
}

ManualScene::~ManualScene()
{
}

void ManualScene::Update()
{
	Button::ButtonSystem(buttons);
	// 左側の文字進める
	if (!messageLeft.IsFinished()) {
		messageLeft.Update();
	}
	// 左が終わったら右進める
	else {
		messageRight.Update();
	}
}

void ManualScene::Draw()
{
	// 背景
	DrawGraph(530, 150, ImageManager::Get("manualBG"), TRUE);
	// ボタン描画
	for (auto& button : buttons)
	{
		button.Draw();
	}
	// 左側の文字描画
	messageLeft.Draw(570,350,GetColor(180, 160, 0),fontHandl);
	// 右側の文字描画
	messageRight.Draw(990,350,GetColor(180, 160, 0),fontHandl);
}
