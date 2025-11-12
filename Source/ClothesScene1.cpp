#include "ClothesScene1.h"
#include "ClothesData.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"
#include <iostream>
#include "OverlayAnimation.h"

ClothesScene1::ClothesScene1()
{
	ImageManager::LoadAll();
	// Get the image handle
	int clothesBack = ImageManager::Get("back");
	int back = ImageManager::Get("-1");
	int next = ImageManager::Get("+1");
	int body1 = ImageManager::Get("BodyArmor1");
	int body2 = ImageManager::Get("BodyArmor2");
	int body3 = ImageManager::Get("BodyArmor3");
	int body4 = ImageManager::Get("BodyArmor4");
	int body5 = ImageManager::Get("BodyArmor5");

	// Overwrite button
	//[this] をキャプチャに入れることで、ラムダ内から scoreText にアクセスできる
	
	buttons.emplace_back(ClothesData::clothes_1ButtonX, ClothesData::clothesButtonY, 100, 100, "Armor_1", body1, [this]() {
		ClothesData::SetSelectedArmor(ImageManager::Get("BodyArmor1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("body1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("body1");
		});
	buttons.emplace_back(ClothesData::clothes_2ButtonX, ClothesData::clothesButtonY, 100, 100, "Armor_2", body2, [this]() {
		ClothesData::SetSelectedArmor(ImageManager::Get("BodyArmor2"));
		ClothesData::SetSelectedEquipmentID("body2");
		ClothesData::UpdateScoreAndExplanation("body2");
		});
	buttons.emplace_back(ClothesData::clothes_3ButtonX, ClothesData::clothesButtonY, 100, 100, "Armor_3", body3, [this]() {
		ClothesData::SetSelectedArmor(ImageManager::Get("BodyArmor3"));
		ClothesData::SetSelectedEquipmentID("body3");
		ClothesData::UpdateScoreAndExplanation("body3");
		});
	buttons.emplace_back(ClothesData::clothes_4ButtonX, ClothesData::clothesButtonY, 100, 100, "Armor_4", body4, [this]() {
		ClothesData::SetSelectedArmor(ImageManager::Get("BodyArmor4"));
		ClothesData::SetSelectedEquipmentID("body4");
		ClothesData::UpdateScoreAndExplanation("body4");
		});
	buttons.emplace_back(ClothesData::clothes_5ButtonX, ClothesData::clothesButtonY, 100, 100, "Armor_5", body5, [this]() {
		ClothesData::SetSelectedArmor(ImageManager::Get("BodyArmor5"));
		ClothesData::SetSelectedEquipmentID("body5");
		ClothesData::UpdateScoreAndExplanation("body5");
		});


	buttons.emplace_back(ClothesData::sceneBackButtonX, ClothesData::sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ClothesData::backButtonX, ClothesData::backNextbuttonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES4");
		});
	buttons.emplace_back(ClothesData::nextButtonX, ClothesData::backNextbuttonY, 150, 150, "Next", next, []() {
		OverlayManager::ShowOverlay("CLOTHES2");
		});

	isInitialized = true; // 初期化したよ

	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 25, 0);
}

ClothesScene1::~ClothesScene1()
{
}

void ClothesScene1::Update()
{

	if (OverlayManager::isOverlayVisible)
	{
		// 初回だけ初期化
		if (OverlayManager::overlayJustOpened && !OverlayManager::playedAnimation)
		{
		    overlayAnim = OverlayAnimation(ImageManager::Get("equipment1")); // 初回のみ再生
			// 各装備追加
			overlayAnim.AddPart(ImageManager::Get("BodyArmor1"), 400, -720, 400, 560, 0.2f);
			overlayAnim.AddPart(ImageManager::Get("BodyArmor2"), 530, -720, 530, 560, 0.2f);
			overlayAnim.AddPart(ImageManager::Get("BodyArmor3"), 660, -720, 660, 560, 0.2f);
			overlayAnim.AddPart(ImageManager::Get("BodyArmor4"), 790, -720, 790, 560, 0.2f);
			overlayAnim.AddPart(ImageManager::Get("BodyArmor5"), 920, -720, 920, 560, 0.2f);
			
			OverlayManager::overlayJustOpened = false;
			OverlayManager::playedAnimation = true; // 再生済みフラグをセット
		}
		// アニメーションがまだ終わってないなら進める
		if (!overlayAnim.IsFinished())
		{
			overlayAnim.Update(); //アニメーション
		}
	}

	Button::ButtonSystem(buttons);//Button System
}

void ClothesScene1::Draw()
{
	// 通常の背景描画

	//　オーバーレイしたとき画面表示アニメーション
	if (OverlayManager::isOverlayVisible)
	{
		// アニメーション中
		if (!overlayAnim.IsFinished())
		{
			overlayAnim.Draw(); // アニメーション描画
		}
		else
		{
			DrawGraph(70, 125, ImageManager::Get("equipment1"), TRUE);
		}
	}
	
	
	//　ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	int armorImage = ClothesData::GetSelectedArmor();
	if (armorImage != -1)
	{
		// Display Position
		int drawX = 240;
		int drawY = 380;

		DrawGraph(drawX, drawY, armorImage, TRUE);
	}

	//装備の説明表示
	DrawFormatStringToHandle(1450, 500, GetColor(255, 255, 255),fontHandl, "%s", ClothesData::scoreText.c_str());
	DrawFormatStringToHandle(1450, 540, GetColor(255, 255, 255),fontHandl, "%s", ClothesData::explanationText.c_str());
	//DrawFormatString(1500, 500, GetColor(255, 255, 255), "%s", ClothesData::scoreText.c_str());
	//DrawFormatString(1500, 540, GetColor(255, 255, 255), "%s", ClothesData::explanationText.c_str());
}

