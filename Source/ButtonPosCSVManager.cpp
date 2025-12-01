#include "ButtonPosCSVManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
// 定義
ButtonPosCSVManager::ButtonPos ButtonPosCSVManager::pos; 
std::vector<ButtonPosCSVManager::ButtonPos> ButtonPosCSVManager::positions;

void ButtonPosCSVManager::LoadPositionsCSV(const std::string& csvPath)
{
	std::ifstream file(csvPath);// 指定したファイル開く
	if (!file.is_open())
	{
		std::cerr << "failed to open CSV file:" << csvPath << std::endl;
		return;
	}
	std::string line;
	getline(file, line);// 一行目はスキップ

	while (getline(file, line))
	{
		std::stringstream ss(line); //stringstream でその行(line)をさらにカンマで区切る
		std::string BackButtonX, BackNextButtonY, NextButtonX, SceneBackButtonX, SceneBackButtonY, 
			        Clothes1X, Clothes2X, Clothes3X, Clothes4X, Clothes5X, ClothesButtonY;

		// getline = 1行分の文字列を読み取る関数 
		// 読み込めなかったら無視して次の行に行く

		if (!std::getline(ss, BackButtonX, ','))continue;
		if (!std::getline(ss, BackNextButtonY, ','))continue;
		if (!std::getline(ss, NextButtonX, ','))continue;
		if (!std::getline(ss, SceneBackButtonX, ','))continue;
		if (!std::getline(ss, SceneBackButtonY, ','))continue;
		if (!std::getline(ss, Clothes1X, ','))continue;
		if (!std::getline(ss, Clothes2X, ','))continue;
		if (!std::getline(ss, Clothes3X, ','))continue;
		if (!std::getline(ss, Clothes4X, ','))continue;
		if (!std::getline(ss, Clothes5X, ','))continue;
		if (!std::getline(ss, ClothesButtonY, ','))continue;

		// 文字列→数値に変換　　 std::stoiでintに変換できる
		pos.backButtonX = std::stoi(BackButtonX);
		pos.backNextButtonY = std::stoi(BackNextButtonY);
		pos.nextButtonX = std::stoi(NextButtonX);
		pos.sceneBackButtonX = std::stoi(SceneBackButtonX);
		pos.sceneBackButtonY = std::stoi(SceneBackButtonY);
		pos.clothes1X = std::stoi(Clothes1X);
		pos.clothes2X = std::stoi(Clothes2X);
		pos.clothes3X = std::stoi(Clothes3X);
		pos.clothes4X = std::stoi(Clothes4X);
		pos.clothes5X = std::stoi(Clothes5X);
		pos.clothesButtonY = std::stoi(ClothesButtonY);

		// CSVから読み込んだ１行分のデータを、全体のリストに追加する
		positions.push_back(pos);
	}
}

// ボタン座標を返す関数
std::pair<int, int> ButtonPosCSVManager::GetButtonPosition(ButtonNo no)
{
	int x = 0;
	int y = pos.clothesButtonY; // Yは共通
	switch (no)
	{
	case ButtonPosCSVManager::ButtonNo_1:
		x = pos.clothes1X;
		break;
	case ButtonPosCSVManager::ButtonNo_2:
		x = pos.clothes2X;
		break;
	case ButtonPosCSVManager::ButtonNo_3:
		x = pos.clothes3X;
		break;
	case ButtonPosCSVManager::ButtonNo_4:
		x = pos.clothes4X;
		break;
	case ButtonPosCSVManager::ButtonNo_5:
		x = pos.clothes5X;
		break;
	default:
		break;
	}
	return { x, y };
}
