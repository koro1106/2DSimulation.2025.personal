#include "ClothesScene1.h"
#include "ClothesData.h"
#include "ImageManager.h"
#include "SoundManager.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"
#include <iostream>
#include "OverlayAnimation.h"
#include "ButtonPosCSVManager.h"

ClothesScene1::ClothesScene1()
{
	//ImageManager::LoadAll();
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
	//[this]入れることで,ラムダ内からscoreTextとかアクセスできるが
	//staticなのでインスタンス不要->[this]いらない
	// emplace_backでコピーしないでそのまま引数渡すだけでOK
	auto [x1, y1] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_1);
	buttons.emplace_back(x1, y1, 100,100, "Armor_1", body1, []() {
		ClothesData::SetSelectedArmor("body1", ImageManager::Get("BodyArmor1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("body1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("body1");
		SoundManager::PlaySE("equipmentClick");
		});
	auto [x2, y2] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_2);
	buttons.emplace_back(x2, y2, 100,100, "Armor_2", body2, []() {
		ClothesData::SetSelectedArmor("body2",ImageManager::Get("BodyArmor2"));
		ClothesData::SetSelectedEquipmentID("body2");
		ClothesData::UpdateScoreAndExplanation("body2");
		SoundManager::PlaySE("equipmentClick");
		});
	auto [x3, y3] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_3);
	buttons.emplace_back(x3, y3, 100, 100, "Armor_3", body3, []() {
		ClothesData::SetSelectedArmor("body3",ImageManager::Get("BodyArmor3"));
		ClothesData::SetSelectedEquipmentID("body3");
		ClothesData::UpdateScoreAndExplanation("body3");
		SoundManager::PlaySE("equipmentClick");
		});
	auto [x4, y4] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_4);
	buttons.emplace_back(x4, y4, 100, 100, "Armor_4", body4, []() {
		ClothesData::SetSelectedArmor("body4",ImageManager::Get("BodyArmor4"));
		ClothesData::SetSelectedEquipmentID("body4");
		ClothesData::UpdateScoreAndExplanation("body4");
		SoundManager::PlaySE("equipmentClick");
		});
	auto [x5, y5] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_5);
	buttons.emplace_back(x5, y5, 100, 100, "Armor_5", body5, []() {
		ClothesData::SetSelectedArmor("body5",ImageManager::Get("BodyArmor5"));
		ClothesData::SetSelectedEquipmentID("body5");
		ClothesData::UpdateScoreAndExplanation("body5");
		SoundManager::PlaySE("equipmentClick");
		});


	buttons.emplace_back(ButtonPosCSVManager::pos.sceneBackButtonX, ButtonPosCSVManager::pos.sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		SoundManager::PlaySE("clickBack");
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.backButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES4");
		SoundManager::PlaySE("click");
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.nextButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Next", next, []() {
		OverlayManager::ShowOverlay("CLOTHES2");
		SoundManager::PlaySE("click");
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
		// 初回のみアニメーション
		if (OverlayManager::overlayJustOpened && !OverlayManager::playedAnimation)
		{
			// 装備ボタンのYを全部-720に
			for (auto& b : buttons)
				b.SetAnimationStart(-720);

			// 背景のアニメ開始
			StartBackgroundAnimation(70, 125);
	
			// CSV の位置へ移動
			auto [x1, y1] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_1);
			auto [x2, y2] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_2);
			auto [x3, y3] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_3);
			auto [x4, y4] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_4);
			auto [x5, y5] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_5);
			
			// 装備５つをCSVの位置へアニメーションセット
			buttons[0].SetAnimation(x1, y1);
			buttons[1].SetAnimation(x2, y2);
			buttons[2].SetAnimation(x3, y3);
			buttons[3].SetAnimation(x4, y4);
			buttons[4].SetAnimation(x5, y5);

			OverlayManager::overlayJustOpened = false;
			OverlayManager::playedAnimation = true;
		}

		// アニメーション処理
		for (auto& btn : buttons)
			btn.UpdateAnimation();

		// 背景アニメーション
		if (!bgAnimFinished)
		{
			bgY += (bgTargetY - bgY) * 0.6f;

			// 終了判定
			if (fabsf(bgTargetY - bgY) < 1) // 目標位置にほぼ到達したら
			{
				bgY = bgTargetY;
				bgAnimFinished = true; // アニメーション終了
			}
		}
		else
		{
			// アニメ完了済みなら常にターゲット座標に固定
			bgY = 125;
		}
	}

	Button::ButtonSystem(buttons);//Button System
}

void ClothesScene1::Draw()
{
	DrawGraph((int)bgX, (int)bgY, ImageManager::Get("equipment1"), TRUE);
	
	// ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	// 装備中の装備表示
	int armorImage = ClothesData::GetSelectedArmorImage();
	if (armorImage != -1)
	{
		DrawGraph(240, 380, armorImage, TRUE);
	}

	//装備の説明表示
	DrawFormatStringToHandle(1450, 380, GetColor(180, 180, 0),fontHandl, "%s", "装備名：");
	DrawFormatStringToHandle(1500, 420, GetColor(180, 180, 0),fontHandl, "%s", ClothesData::nameText.c_str());
	DrawFormatStringToHandle(1460, 540, GetColor(180, 180, 0),fontHandl, "%s", "説明：");
	DrawFormatStringToHandle(1500, 580, GetColor(180, 180, 0),fontHandl, "%s", ClothesData::explanationText.c_str());
	
}

// 背景アニメーション
void ClothesScene1::StartBackgroundAnimation(float tx, float ty)
{
	bgTargetX = tx;
	bgTargetY = ty;
	bgAnimFinished = false;
}

