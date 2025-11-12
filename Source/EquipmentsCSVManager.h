#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct EquipmentData
{
	std::string id;
	std::string name;
	std::string imageFile;
	int score;
	std::string explanation;
};

class EquipmentCSVManager
{
public:
	//CSV Load
	static void LoadEquipmentsCSV(const std::string& csvPath);
	//A function that searches through data loaded from a CSV.
	static const EquipmentData* GetEquipmentByID(const std::string& id);
private:
	static std::vector<EquipmentData> equipmentList;
	static std::unordered_map<std::string, EquipmentData> equipmentMap;// key:id
};
