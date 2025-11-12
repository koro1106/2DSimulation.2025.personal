#pragma once
#include <string>
#include <windows.h>

class ClothesData
{
public:
	static int selectedArmorId;
	static int selectedBeltId;
	static int selectedBracersId;
	static int selectedBootsId;

	// ClothesScene Button ImagePosition
	static const int backButtonX = 260;
	static const int backNextbuttonY = 845;
	static const int nextButtonX = 915;

	static const int sceneBackButtonX = 30;
	static const int sceneBackButtonY = 90;

	static const int clothes_1ButtonX = 400;
	static const int clothes_2ButtonX = 530;
	static const int clothes_3ButtonX = 660;
	static const int clothes_4ButtonX = 790;
	static const int clothes_5ButtonX = 920;
	static const int clothesButtonY = 560;

	// Armor
	static void SetSelectedArmor(int imageId);
	static int GetSelectedArmor();
	// Belt
	static void SetSelectedBelt(int imageId);
	static int GetSelectedBelt();
	// Bracers
	static void SetSelectedBracers(int imageId);
	static int GetSelectedBracers();
	// Boots
	static void SetSelectedBoots(int imageId);
	static int GetSelectedBoots();
	// Equipment ImageFilePath
	static void SetSelectedEquipmentID(const std::string& path);
	static const std::string& GetSelectedEquipmentID();

	static std::string selectedEquipmentID;

	//Update Score and Explanation
	static void UpdateScoreAndExplanation(const std::string& equipmentID);
	static std::string scoreText;
	static std::string explanationText;

	// UTF-8 Å® Shift-JISïœä∑ä÷êî
	static std::string Utf8ToSjis(const std::string& src)
	{
		int wlen = MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, NULL, 0);
		std::wstring wstr(wlen, L'\0');
		MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, &wstr[0], wlen);

		int slen = WideCharToMultiByte(932, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
		std::string str(slen, '\0');
		WideCharToMultiByte(932, 0, wstr.c_str(), -1, &str[0], slen, NULL, NULL);
		return str;
	}
};