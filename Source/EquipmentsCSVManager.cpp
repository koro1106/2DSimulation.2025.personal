#include "EquipmentsCSVManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <DxLib.h>

// 定義しかされてないから実体作る
std::vector<EquipmentData> EquipmentCSVManager::equipmentList; // CSV順に装備を保持するリスト
std::unordered_map<std::string, EquipmentData> EquipmentCSVManager::equipmentMap; // 装備IDで直接検索できるマップ

void EquipmentCSVManager::LoadEquipmentsCSV(const std::string& csvPath)
{
	std::ifstream file(csvPath);
	if (!file.is_open())
	{
		std::cerr << "Equipment CSV open failed:" << csvPath << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);//　一行目はスキップ

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string field;

		EquipmentData data;
		std::getline(ss, data.id, ',');
		std::getline(ss, data.name, ',');
		std::getline(ss, field, ',');
		data.score = std::stoi(field); // stoi =　intに変える
	    std::getline(ss, data.explanation, ',');

		equipmentList.push_back(data); // リストに追加
		equipmentMap[data.id] = data; //　IDで検索できるようにマップに追加
	}
}

const EquipmentData* EquipmentCSVManager::GetEquipmentByID(const std::string& id)
{
	// equipmentMapから指定のIDを検索
	//見つかれば装備データへのポインタを返す
	auto it = equipmentMap.find(id);
	if (it != equipmentMap.end())
		return &it->second;
	return nullptr;
}
