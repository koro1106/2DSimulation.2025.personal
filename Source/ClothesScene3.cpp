#include "ClothesScene3.h"
#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"


ClothesScene3::ClothesScene3()
{
	ImageManager::LoadAll();
	// Get the image handle
	int clothesBack = ImageManager::Get("back");
	int back = ImageManager::Get("-1");
	int next = ImageManager::Get("+1");
	int bracers1 = ImageManager::Get("Bracers1");
	int bracers2 = ImageManager::Get("Bracers2");
	int bracers3 = ImageManager::Get("Bracers3");
	int bracers4 = ImageManager::Get("Bracers4");
	int bracers5 = ImageManager::Get("Bracers5");

	// Overwrite button
	buttons.emplace_back(ClothesData::clothes_1ButtonX, ClothesData::clothesButtonY, 100, 100, "Bracers_1", bracers1, [this]() {
		ClothesData::SetSelectedBracers(ImageManager::Get("Bracers1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("bracers1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("bracers1");
		});
	buttons.emplace_back(ClothesData::clothes_2ButtonX, ClothesData::clothesButtonY, 100, 100, "Bracers_2", bracers2, [this]() {
		ClothesData::SetSelectedBracers(ImageManager::Get("Bracers2"));
		ClothesData::SetSelectedEquipmentID("bracers2");
		ClothesData::UpdateScoreAndExplanation("bracers2");
		});
	buttons.emplace_back(ClothesData::clothes_3ButtonX, ClothesData::clothesButtonY, 100, 100, "Bracers_3", bracers3, [this]() {
		ClothesData::SetSelectedBracers(ImageManager::Get("Bracers3"));
		ClothesData::SetSelectedEquipmentID("bracers3");
		ClothesData::UpdateScoreAndExplanation("bracers3");
		});
	buttons.emplace_back(ClothesData::clothes_4ButtonX, ClothesData::clothesButtonY, 100, 100, "Bracers_4", bracers4, [this]() {
		ClothesData::SetSelectedBracers(ImageManager::Get("Bracers4"));
		ClothesData::SetSelectedEquipmentID("bracers4");
		ClothesData::UpdateScoreAndExplanation("bracers4");
		});
	buttons.emplace_back(ClothesData::clothes_5ButtonX, ClothesData::clothesButtonY, 100, 100, "Bracers_5", bracers5, [this]() {
		ClothesData::SetSelectedBracers(ImageManager::Get("Bracers5"));
		ClothesData::SetSelectedEquipmentID("bracers5");
		ClothesData::UpdateScoreAndExplanation("bracers5");
		});

	buttons.emplace_back(ClothesData::sceneBackButtonX, ClothesData::sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ClothesData::backButtonX, ClothesData::backNextbuttonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES2");
		});
	buttons.emplace_back(ClothesData::nextButtonX, ClothesData::backNextbuttonY, 150, 150, "Next", next, []() {
		OverlayManager::ShowOverlay("CLOTHES4");
		});

	isInitialized = true; // 初期化したよ
	//　フォント登録
	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL);
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 25, 0);
}

ClothesScene3::~ClothesScene3()
{
}

void ClothesScene3::Update()
{
	Button::ButtonSystem(buttons);//Button System
}

void ClothesScene3::Draw()
{
	//BackGround
	DrawGraph(70, 125, ImageManager::Get("equipment3"), TRUE);

	//Button Drawing
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	int bracersImage = ClothesData::GetSelectedBracers();
	if (bracersImage != -1)
	{
		// Display Position
		int drawX = 240;
		int drawY = 380;

		DrawGraph(drawX, drawY, bracersImage, TRUE);
	}

	//装備の説明表示
	DrawFormatStringToHandle(1450, 500, GetColor(255, 255, 255), fontHandl, "%s", ClothesData::scoreText.c_str());
	DrawFormatStringToHandle(1450, 540, GetColor(255, 255, 255), fontHandl, "%s", ClothesData::explanationText.c_str());
}
