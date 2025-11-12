#include "EquipmentDrawer.h"

const int drawX = 75;

void EquipmentDrawer::DrawSelectedEquipment(EquipmentType type)
{
	int img = -1;
	int drawY = 0;
	// 真ん中に表示する選択中の装備画像位置
	int dX = 0;
	int dY = 0;

	switch (type)
	{
	case EquipmentType::Armor:
		img = ClothesData::GetSelectedArmor();
		drawY = 430;
		dX = 1130;
		dY = 255;
		break;
	case EquipmentType::Belt:
		img = ClothesData::GetSelectedBelt();
		drawY = 580;
		dX = 1160;
		dY = 460;
		break;
	case EquipmentType::Bracers:
		img = ClothesData::GetSelectedBracers();
		drawY = 730;
		dX = 680;
		dY = 370;
		break;
	case EquipmentType::Boot:
		img = ClothesData::GetSelectedBoots();
		drawY = 870;
		dX = 680;
		dY = 650;
		break;
	}

	if (img != -1)
	{
		DrawGraph(drawX, drawY, img, TRUE); // 画面左に装備中の画像表示
		DrawGraph(dX, dY, img, TRUE); // 画面中央に装備中の画像表示
	}
}
