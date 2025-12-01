#include "ClothesScene4.h"
#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"
#include "ButtonPosCSVManager.h"

ClothesScene4::ClothesScene4()
{
	ImageManager::LoadAll();
	// Get the image handle
	int clothesBack = ImageManager::Get("back");
	int back = ImageManager::Get("-1");
	int next = ImageManager::Get("+1");
	int boots1 = ImageManager::Get("Boots1");
	int boots2 = ImageManager::Get("Boots2");
	int boots3 = ImageManager::Get("Boots3");
	int boots4 = ImageManager::Get("Boots4");
	int boots5 = ImageManager::Get("Boots5");

	// Overwrite button
	auto [x1, y1] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_1);
	buttons.emplace_back(x1, y1, 100, 100, "Boots_1", boots1, []() {
		ClothesData::SetSelectedBoots("boots1",ImageManager::Get("Boots1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("boots1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("boots1");
		});
	auto [x2, y2] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_2);
	buttons.emplace_back(x2, y2, 100, 100, "Boots_2", boots2, []() {
		ClothesData::SetSelectedBoots("boots2",ImageManager::Get("Boots2"));
		ClothesData::SetSelectedEquipmentID("boots2");
		ClothesData::UpdateScoreAndExplanation("boots2");
		});
	auto [x3, y3] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_3);
	buttons.emplace_back(x3, y3, 100, 100, "Boots_3", boots3, []() {
		ClothesData::SetSelectedBoots("boots3", ImageManager::Get("Boots3"));
		ClothesData::SetSelectedEquipmentID("boots3");
		ClothesData::UpdateScoreAndExplanation("boots3");
		});
	auto [x4, y4] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_4);
	buttons.emplace_back(x4, y4, 100, 100, "Boots_4", boots4, []() {
		ClothesData::SetSelectedBoots("boots4", ImageManager::Get("Boots4"));
		ClothesData::SetSelectedEquipmentID("boots4");
		ClothesData::UpdateScoreAndExplanation("boots4");
		});
	auto [x5, y5] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_5);
	buttons.emplace_back(x5, y5, 100, 100, "Boots_5", boots5, []() {
		ClothesData::SetSelectedBoots("boots5", ImageManager::Get("Boots5"));
		ClothesData::SetSelectedEquipmentID("boots5");
		ClothesData::UpdateScoreAndExplanation("boots5");
		});

	buttons.emplace_back(ButtonPosCSVManager::pos.sceneBackButtonX, ButtonPosCSVManager::pos.sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.backButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES3");
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.nextButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Next", next, []() {
		OverlayManager::ShowOverlay("CLOTHES1");
		});

	isInitialized = true; // 初期化したよ
	//　フォント登録
	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL);
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 25, 0);
}

ClothesScene4::~ClothesScene4()
{
}

void ClothesScene4::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void ClothesScene4::Draw()
{

	//BackGround
	DrawGraph(70, 125, ImageManager::Get("equipment4"), TRUE);

	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	//選択装備更新
	int bootsImage = ClothesData::GetSelectedBootsImage();
	if (bootsImage != -1)
	{
		// Display Position
		int drawX = 240;
		int drawY = 380;

		DrawGraph(drawX, drawY, bootsImage, TRUE);
	}

	//装備の説明表示
	DrawFormatStringToHandle(1450, 500, GetColor(255, 255, 255), fontHandl, "%s", ClothesData::scoreText.c_str());
	DrawFormatStringToHandle(1450, 540, GetColor(255, 255, 255), fontHandl, "%s", ClothesData::explanationText.c_str());
}
