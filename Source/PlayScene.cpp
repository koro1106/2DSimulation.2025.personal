#include "PlayScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "ClothesData.h"
#include "EquipmentDrawer.h"

PlayScene::PlayScene()
   :light1(1640, 180, 28), // コンストラクタ読んで初期化
   light2(1580, 285, 28),
   light3(1625, 385, 28)
{
	ImageManager::LoadAll();
	// Get the image handle
	int bg4Image = ImageManager::Get("bg4");
	int list = ImageManager::Get("list");
	int hatena = ImageManager::Get("hatena");
	int book = ImageManager::Get("book");
	int setting = ImageManager::Get("setting");
	int exit = ImageManager::Get("exit");

	buttons.emplace_back(1770, 530, 149, 148, "Title", setting); //タイトルに戻る
	buttons.emplace_back(1590, 860, 280, 174, "Exit", exit, []() { // リザルト画面
		OverlayManager::ShowOverlay("RESULTCHECK");
		});

	buttons.emplace_back(20, 340, 379, 720, "Clothes", bg4Image, []() { // 装備画面 
		OverlayManager::ShowOverlay("CLOTHES1");
		OverlayManager::isOverlayVisible = true;
	});
	buttons.emplace_back(1770, 130, 120, 120, "List", list, []() {
		OverlayManager::ShowOverlay("LIST");
	});
	buttons.emplace_back(1770, 330, 110, 126, "Manual", hatena, []() {
		OverlayManager::ShowOverlay("MANUAL");
	});

	SetMouseDispFlag(FALSE); //　OSのマウスカーソル消す

}

PlayScene::~PlayScene()
{
}
void PlayScene::Update()
{
	// マウス位置
	GetMousePoint(&mx, &my);

	if (OverlayManager::isOverlayVisible)
	{
		OverlayManager::Update();
	}
	else {
		GetMousePoint(&mouseX, &mouseY);
		bool isMousePressed = (GetMouseInput() & MOUSE_INPUT_LEFT);

		//Button
		for (auto& button : buttons)
		{
			if (button.IsMouseOver(mouseX, mouseY))
			{
				//クリックした瞬間だけ
				if (isMousePressed && !prevButton)
				{
					button.OnClick();
				}
			}
		}
		//Save the previous input
		prevButton = isMousePressed;
	}
}
void PlayScene::Draw()
{
	//BackGround
	DrawGraph(0, 0, ImageManager::Get("bg1"), TRUE);
	DrawGraph(400, 20, ImageManager::Get("bg2"), TRUE);
	DrawGraph(1670,20, ImageManager::Get("optionBG"), TRUE);
	//DrawGraph(880, 240, ImageManager::Get("human"), TRUE);
	DrawGraph(500, 60, ImageManager::Get("h1"), TRUE);
	DrawGraph(1820, 170, ImageManager::Get("bgList"), TRUE);
	// TextImage
	DrawGraph(1740, 100, ImageManager::Get("listText"), TRUE);
	DrawGraph(1740, 305, ImageManager::Get("manualText"), TRUE);
	DrawGraph(1740, 510, ImageManager::Get("titleText"), TRUE);
	// 光源を描画
	light1.Draw(); 
	light2.Draw(); 
	light3.Draw(); 


	//Button Drawing
	for (auto& button : buttons)
	{
		button.Draw();
	}

	DrawGraph(60, 300, ImageManager::Get("namePlate"), TRUE);

	// 選択中の装備表示
	EquipmentDrawer::DrawSelectedEquipment(EquipmentType::Armor);
	EquipmentDrawer::DrawSelectedEquipment(EquipmentType::Belt);
	EquipmentDrawer::DrawSelectedEquipment(EquipmentType::Bracers);
	EquipmentDrawer::DrawSelectedEquipment(EquipmentType::Boot);


	if (OverlayManager::isOverlayVisible) {
		OverlayManager::Draw();
	}

	// マウスカーソル
	DrawGraph(mx, my, ImageManager::Get("cursor"), TRUE);
}
