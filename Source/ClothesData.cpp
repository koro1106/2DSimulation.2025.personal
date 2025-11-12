#include "ClothesData.h"
#include "EquipmentsCSVManager.h"
#include <string>

int ClothesData::selectedArmorId = -1;
int ClothesData::selectedBeltId = -1;
int ClothesData::selectedBracersId = -1;
int ClothesData::selectedBootsId = -1;

std::string ClothesData::selectedEquipmentID = "";
std::string ClothesData::scoreText = "";
std::string ClothesData::explanationText = "";

// Armor
void ClothesData::SetSelectedArmor(int imageId)
{
	selectedArmorId = imageId;
}

int ClothesData::GetSelectedArmor()
{
	return selectedArmorId;
}

// Belt
void ClothesData::SetSelectedBelt(int imageId)
{
	selectedBeltId = imageId;
}

int ClothesData::GetSelectedBelt()
{
	return selectedBeltId;
}

// Bracers
void ClothesData::SetSelectedBracers(int imageId)
{
	selectedBracersId = imageId;
}

int ClothesData::GetSelectedBracers()
{
	return selectedBracersId;
}

// Boots
void ClothesData::SetSelectedBoots(int imageId)
{
	selectedBootsId = imageId;
}

int ClothesData::GetSelectedBoots()
{
	return selectedBootsId;
}

// 装備のIDセットする
void ClothesData::SetSelectedEquipmentID(const std::string& path)
{
	selectedEquipmentID = path;
}

const std::string& ClothesData::GetSelectedEquipmentID()
{
	return selectedEquipmentID;
}

//装備の説明アップデート関数
void ClothesData::UpdateScoreAndExplanation(const std::string& equipmentID)
{
	const EquipmentData* equipment = EquipmentCSVManager::GetEquipmentByID(equipmentID);
	if (equipment != nullptr)
	{
		if (equipment != nullptr) {
			// UTF-8 → Shift-JIS変換
			std::string explanationSJIS = Utf8ToSjis(equipment->explanation);
			
			scoreText = "スコア：" + std::to_string(equipment->score);
			explanationText = "説明：" + explanationSJIS;
		}
		else {
			scoreText = "スコア：不明";
			explanationText = "説明：見つからない";
		}
	}
}
