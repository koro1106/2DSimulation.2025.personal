#include "ClothesScene1.h"
#include "ClothesData.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"
#include <iostream>
#include "OverlayAnimation.h"
#include "ButtonPosCSVManager.h"

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
	//[this]入れることで,ラムダ内からscoreTextとかアクセスできるが
	//staticなのでインスタンス不要->[this]いらない
	// emplace_backでコピーしないでそのまま引数渡すだけでOK
	auto [x1, y1] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_1);
	buttons.emplace_back(x1,y1,100,100, "Armor_1", body1, []() {
		ClothesData::SetSelectedArmor("body1", ImageManager::Get("BodyArmor1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("body1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("body1");
		});
	auto [x2, y2] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_2);
	buttons.emplace_back(x2,y2,100,100, "Armor_2", body2, []() {
		ClothesData::SetSelectedArmor("body2",ImageManager::Get("BodyArmor2"));
		ClothesData::SetSelectedEquipmentID("body2");
		ClothesData::UpdateScoreAndExplanation("body2");
		});
	auto [x3, y3] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_3);
	buttons.emplace_back(x3, y3, 100, 100, "Armor_3", body3, []() {
		ClothesData::SetSelectedArmor("body3",ImageManager::Get("BodyArmor3"));
		ClothesData::SetSelectedEquipmentID("body3");
		ClothesData::UpdateScoreAndExplanation("body3");
		});
	auto [x4, y4] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_4);
	buttons.emplace_back(x4, y4, 100, 100, "Armor_4", body4, []() {
		ClothesData::SetSelectedArmor("body4",ImageManager::Get("BodyArmor4"));
		ClothesData::SetSelectedEquipmentID("body4");
		ClothesData::UpdateScoreAndExplanation("body4");
		});
	auto [x5, y5] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_5);
	buttons.emplace_back(x5, y5, 100, 100, "Armor_5", body5, []() {
		ClothesData::SetSelectedArmor("body5",ImageManager::Get("BodyArmor5"));
		ClothesData::SetSelectedEquipmentID("body5");
		ClothesData::UpdateScoreAndExplanation("body5");
		});


	buttons.emplace_back(ButtonPosCSVManager::pos.sceneBackButtonX, ButtonPosCSVManager::pos.sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.backButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES4");
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.nextButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Next", next, []() {
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

	int armorImage = ClothesData::GetSelectedArmorImage();
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
	
}

