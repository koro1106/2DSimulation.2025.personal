#include "ClothesScene3.h"
#include "ImageManager.h"
#include "ClothesData.h"
#include "OverlayManager.h"
#include "EquipmentsCSVManager.h"
#include "ButtonPosCSVManager.h"

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
	auto [x1, y1] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_1);
	buttons.emplace_back(x1, y1, 100, 100, "Bracers_1", bracers1, []() {
		ClothesData::SetSelectedBracers("bracers1",ImageManager::Get("Bracers1"));// 装備中の装備画像セット
		ClothesData::SetSelectedEquipmentID("bracers1");// 装備IDセット
		ClothesData::UpdateScoreAndExplanation("bracers1");
		});
	auto [x2, y2] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_2);
	buttons.emplace_back(x2, y2, 100, 100, "Bracers_2", bracers2, []() {
		ClothesData::SetSelectedBracers("bracers2",ImageManager::Get("Bracers2"));
		ClothesData::SetSelectedEquipmentID("bracers2");
		ClothesData::UpdateScoreAndExplanation("bracers2");
		});
	auto [x3, y3] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_3);
	buttons.emplace_back(x3, y3, 100, 100, "Bracers_3", bracers3, []() {
		ClothesData::SetSelectedBracers("bracers3",ImageManager::Get("Bracers3"));
		ClothesData::SetSelectedEquipmentID("bracers3");
		ClothesData::UpdateScoreAndExplanation("bracers3");
		});
	auto [x4, y4] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_4);
	buttons.emplace_back(x4, y4, 100, 100, "Bracers_4", bracers4, []() {
		ClothesData::SetSelectedBracers("bracers4",ImageManager::Get("Bracers4"));
		ClothesData::SetSelectedEquipmentID("bracers4");
		ClothesData::UpdateScoreAndExplanation("bracers4");
		});
	auto [x5, y5] = ButtonPosCSVManager::GetButtonPosition(ButtonPosCSVManager::ButtonNo_5);
	buttons.emplace_back(x5, y5, 100, 100, "Bracers_5", bracers5, []() {
		ClothesData::SetSelectedBracers("bracers5",ImageManager::Get("Bracers5"));
		ClothesData::SetSelectedEquipmentID("bracers5");
		ClothesData::UpdateScoreAndExplanation("bracers5");
		});

	buttons.emplace_back(ButtonPosCSVManager::pos.sceneBackButtonX, ButtonPosCSVManager::pos.sceneBackButtonY, 120, 93, "SceneBack", clothesBack, []() {
		OverlayManager::HideOverlay();
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.backButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Back", back, []() {
		OverlayManager::ShowOverlay("CLOTHES2");
		});
	buttons.emplace_back(ButtonPosCSVManager::pos.nextButtonX, ButtonPosCSVManager::pos.backNextButtonY, 150, 150, "Next", next, []() {
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

	int bracersImage = ClothesData::GetSelectedBracersImage();
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
