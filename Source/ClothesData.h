#pragma once
#include <string>
#include <windows.h>

class ClothesData
{
public:
	// 選択中の装備画像ID
	static int selectedArmorId;
	static int selectedBeltId;
	static int selectedBracersId;
	static int selectedBootsId;

	// 各装装備のID
	static std::string armorID;
	static std::string beltID;
	static std::string bracersID;
	static std::string bootsID;

	// Armor
	static void SetSelectedArmor(const std::string& id, int imageId);
	static int GetSelectedArmorScore();
	static int GetSelectedArmorImage(); // 画像取得
	// Belt
	static void SetSelectedBelt(const std::string& id, int imageId);
	static int GetSelectedBeltScore();
	static int GetSelectedBeltImage(); // 画像取得
	// Bracers
	static void SetSelectedBracers(const std::string& id, int imageId);
	static int GetSelectedBracersScore();
	static int GetSelectedBracersImage(); // 画像取得
	// Boots
	static void SetSelectedBoots(const std::string& id, int imageId);
	static int GetSelectedBootsScore();
	static int GetSelectedBootsImage(); // 画像取得
	// Equipment ImageFilePath
	static void SetSelectedEquipmentID(const std::string& id);
	static const std::string& GetSelectedEquipmentID();

	//選択中の装備の説明
	static void UpdateScoreAndExplanation(const std::string& equipmentID);
	static std::string scoreText;
	static std::string explanationText;

	// 各装備スコアの取得
	static int GetArmorScore();
	static int GetBeltScore();
	static int GetBracersScore();
	static int GetBootsScore();

	// UTF-8 → Shift-JIS変換関数
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

	static std::string selectedEquipmentID;
};