#include "ClothesData.h"
#include "EquipmentsCSVManager.h"
#include <string>

// 画像ID
int ClothesData::selectedArmorId = -1;
int ClothesData::selectedBeltId = -1;
int ClothesData::selectedBracersId = -1;
int ClothesData::selectedBootsId = -1;

// 装備ID（CSV参照用）
std::string ClothesData::armorID = "";
std::string ClothesData::beltID = "";
std::string ClothesData::bracersID = "";
std::string ClothesData::bootsID = "";

std::string ClothesData::scoreText = "";
std::string ClothesData::explanationText = "";

std::string ClothesData::selectedEquipmentID = "";

//セッター（画像ID＋装備ID を登録）
// Armor
void ClothesData::SetSelectedArmor(const std::string& id, int imageId)
{
	selectedArmorId = imageId;
	armorID = id;
}
// Belt
void ClothesData::SetSelectedBelt(const std::string& id, int imageId)
{
	selectedBeltId = imageId;
	beltID = id;
}
// Bracers
void ClothesData::SetSelectedBracers(const std::string& id, int imageId)
{
	selectedBracersId = imageId;
	bracersID = id;
}
// Boots
void ClothesData::SetSelectedBoots(const std::string& id, int imageId)
{
	selectedBootsId = imageId;
	bootsID = id;
}

void ClothesData::SetSelectedEquipmentID(const std::string& id)
{
	selectedEquipmentID = id;
}

// スコア取得
int ClothesData::GetSelectedArmorScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(armorID);
	return (e ? e->score : 0); // eにスコア入ってたらスコア入れるそうでなくれば０
}

int ClothesData::GetSelectedArmorImage()
{
	return selectedArmorId; // 選択中の画像取得
}

int ClothesData::GetSelectedBeltScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(beltID);
	return (e ? e->score : 0);
}

int ClothesData::GetSelectedBeltImage()
{
    return 	selectedBeltId; // 選択中の画像取得
}

int ClothesData::GetSelectedBracersScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(bracersID);
	return (e ? e->score : 0);
}

int ClothesData::GetSelectedBracersImage()
{
	return selectedBracersId; // 選択中の画像取得
}

int ClothesData::GetSelectedBootsScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(bootsID);
	return (e ? e->score : 0);
}

int ClothesData::GetSelectedBootsImage()
{
	return selectedBootsId; // 選択中の画像取得
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

// 装備中のスコア
int ClothesData::GetArmorScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(armorID);
	return e ? e->score : 0;
}

int ClothesData::GetBeltScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(beltID);
	return e ? e->score : 0;
}

int ClothesData::GetBracersScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(bracersID);
	return e ? e->score : 0;
}

int ClothesData::GetBootsScore()
{
	auto e = EquipmentCSVManager::GetEquipmentByID(bootsID);
	return e ? e->score : 0;
}
