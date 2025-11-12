#include "ClothesScene2.h"
#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"


ClothesScene2::ClothesScene2()
{
	ImageManager::LoadAll();
	// Get the image handle
	int clothesBack = ImageManager::Get("back");
	int back = ImageManager::Get("-1");
	int next = ImageManager::Get("+1");
	int belt1 = ImageManager::Get("Belt1");
	int belt2 = ImageManager::Get("Belt2");
	int belt3 = ImageManager::Get("Belt3");
	int belt4 = ImageManager::Get("Belt4");
	int belt5 = ImageManager::Get("Belt5");

	// Overwrite button
	buttons.emplace_back(ClothesData::clothes_1ButtonX, ClothesData::clothesButtonY, 100, 100, "Belt_1", belt1, [this]() {
		ClothesData::SetSelectedBelt(ImageManager::Get("Belt1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("belt1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("belt1");
		});
	buttons.emplace_back(ClothesData::clothes_2ButtonX, ClothesData::clothesButtonY, 100, 100, "Belt_2", belt2, [this]() {
		ClothesData::SetSelectedBelt(ImageManager::Get("Belt2"));
		ClothesData::SetSelectedEquipmentID("belt2");
		ClothesData::UpdateScoreAndExplanation("belt2");
		});
	buttons.emplace_back(ClothesData::clothes_3ButtonX, ClothesData::clothesButtonY, 100, 100, "Belt_3", belt3, [this]() {
		ClothesData::SetSelectedBelt(ImageManager::Get("Belt3"));
		ClothesData::SetSelectedEquipmentID("belt3");
		ClothesData::UpdateScoreAndExplanation("belt3");
		});
	buttons.emplace_back(ClothesData::clothes_4ButtonX, ClothesData::clothesButtonY, 100, 100, "Belt_4", belt4, [this]() {
		ClothesData::SetSelectedBelt(ImageManager::Get("Belt4"));
		ClothesData::SetSelectedEquipmentID("belt4");
		ClothesData::UpdateScoreAndExplanation("belt4");
		});
	buttons.emplace_back(ClothesData::clothes_5ButtonX, ClothesData::clothesButtonY, 100, 100, "Belt_5", belt5, [this]() {
		ClothesData::SetSelectedBelt(ImageManager::Get("Belt5"));
		ClothesData::SetSelectedEquipmentID("belt5");
		ClothesData::UpdateScoreAndExplanation("belt5");
		});

	buttons.emplace_back(ClothesData::sceneBackButtonX, ClothesData::sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ClothesData::backButtonX, ClothesData::backNextbuttonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES1");
		});
	buttons.emplace_back(ClothesData::nextButtonX, ClothesData::backNextbuttonY, 150, 150, "Next", next, []() {
		OverlayManager::ShowOverlay("CLOTHES3");
		});

	isInitialized = true; // 初期化したよ

	//　フォント登録
	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL);
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 25, 0);
}

ClothesScene2::~ClothesScene2()
{
}

void ClothesScene2::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void ClothesScene2::Draw()
{
	//BackGround
	DrawGraph(70, 125, ImageManager::Get("equipment2"), TRUE);


	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	int beltImage = ClothesData::GetSelectedBelt();
	if (beltImage != -1)
	{
		// Display Position
		int drawX = 240;
		int drawY = 380;

		DrawGraph(drawX, drawY, beltImage, TRUE);
	}

	//Score & Explanation
//装備の説明表示
	DrawFormatStringToHandle(1450, 500, GetColor(255, 255, 255), fontHandl, "%s", ClothesData::scoreText.c_str());
	DrawFormatStringToHandle(1450, 540, GetColor(255, 255, 255), fontHandl, "%s", ClothesData::explanationText.c_str());
}
