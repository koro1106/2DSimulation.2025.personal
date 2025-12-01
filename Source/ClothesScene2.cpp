#include "ClothesScene2.h"
#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"
#include "ButtonPosCSVManager.h"

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
	auto [x1, y1] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_1);
	buttons.emplace_back(x1, y1, 100, 100, "Belt_1", belt1, []() {
		ClothesData::SetSelectedBelt("belt1",ImageManager::Get("Belt1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("belt1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("belt1");
		});
	auto [x2, y2] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_2);
	buttons.emplace_back(x2, y2, 100, 100, "Belt_2", belt2, []() {
		ClothesData::SetSelectedBelt("belt2", ImageManager::Get("Belt2"));
		ClothesData::SetSelectedEquipmentID("belt2");
		ClothesData::UpdateScoreAndExplanation("belt2");
		});
	auto [x3, y3] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_3);
	buttons.emplace_back(x3, y3, 100, 100, "Belt_3", belt3, []() {
		ClothesData::SetSelectedBelt("belt3", ImageManager::Get("Belt3"));
		ClothesData::SetSelectedEquipmentID("belt3");
		ClothesData::UpdateScoreAndExplanation("belt3");
		});
	auto [x4, y4] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_4);
	buttons.emplace_back(x4, y4, 100, 100, "Belt_4", belt4, []() {
		ClothesData::SetSelectedBelt("belt4", ImageManager::Get("Belt4"));
		ClothesData::SetSelectedEquipmentID("belt4");
		ClothesData::UpdateScoreAndExplanation("belt4");
		});
	auto [x5, y5] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_5);
	buttons.emplace_back(x5, y5, 100, 100, "Belt_5", belt5, []() {
		ClothesData::SetSelectedBelt("belt5", ImageManager::Get("Belt5"));
		ClothesData::SetSelectedEquipmentID("belt5");
		ClothesData::UpdateScoreAndExplanation("belt5");
		});

	buttons.emplace_back(ButtonPosCSVManager::pos.sceneBackButtonX, ButtonPosCSVManager::pos.sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.backButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES1");
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.nextButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Next", next, []() {
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

	int beltImage = ClothesData::GetSelectedBeltImage();
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
