#include "EquipmentsCSVManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <DxLib.h>

std::vector<EquipmentData> EquipmentCSVManager::equipmentList;
std::unordered_map<std::string, EquipmentData> EquipmentCSVManager::equipmentMap;

void EquipmentCSVManager::LoadEquipmentsCSV(const std::string& csvPath)
{
	std::ifstream file(csvPath);
	if (!file.is_open())
	{
		std::cerr << "Equipment CSV open failed:" << csvPath << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);//Skip the first line

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string field;

		EquipmentData data;
		std::getline(ss, data.id, ',');
		std::getline(ss, data.name, ',');
		std::getline(ss, field, ',');
		data.score = std::stoi(field); // stoi = int change
	    std::getline(ss, data.explanation, ',');

		equipmentList.push_back(data); // Add to list
		equipmentMap[data.id] = data; //Saved for search
	}
}

const EquipmentData* EquipmentCSVManager::GetEquipmentByID(const std::string& id)
{
	auto it = equipmentMap.find(id);
	if (it != equipmentMap.end())
		return &it->second;
	return nullptr;
}
