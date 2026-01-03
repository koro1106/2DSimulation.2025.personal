#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"
#include "SoundManager.h"

TitleCheck::TitleCheck()
{
	int back = ImageManager::Get("back");
	int yes = ImageManager::Get("yes");

	buttons.emplace_back(390, 250, 120, 93, "SceneBack", back, []() {
		SoundManager::PlaySE("clickBack");
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(810, 610, 217, 74, "Yes", yes, []() {
		SceneManager::ChangeScene("TITLE");
		SoundManager::PlaySE("click");
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

	ScaleAnimation(); // 拡大アニメーション
}
void TitleCheck::Draw()
{
	DrawGraph(450, 260, ImageManager::Get("checkBG"), TRUE);

	int img = ImageManager::Get("checkEdge");
	GetGraphSize(img, &imageWidth, &imageHeight); // 元の画像サイズ取得

	// 画像の中心に合わせて拡大するための描画位置を計算
	int centerX = 520 + imageWidth / 2;
	int centerY = 290 + imageHeight / 2;

	// 拡大した画像の新しい描画位置
	int newWidth = (int)(imageWidth * scale);
	int newHeight = (int)(imageHeight * scale);

	// 新しい左上の座標は、画像の中心から半分だけずらした位置
	int drawX = centerX - newWidth / 2;
	int drawY = centerY - newHeight / 2;

	// 背景のふちの拡大率反映
	DrawExtendGraph(drawX, drawY, drawX + newWidth, drawY + newHeight, img, TRUE);

	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	DrawFormatStringToHandle(630, 450, GetColor(180, 180, 0), fontHandl, "%s", "今日の業務を終了しますか？");
}

// 拡大アニメーション
void TitleCheck::ScaleAnimation()
{

	scale += scaleSpeed;
	// 拡大が目標サイズ(1.2倍)になったらストップ
	if (scale >= 1.2f)
	{
		scale = 1.2f; // 目標サイズに達したらストップ
		scaleSpeed = 0.0f; // それ以上拡大しないように速度を0に
	}
}