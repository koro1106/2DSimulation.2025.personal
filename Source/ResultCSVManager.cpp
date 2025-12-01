#include "ResultCSVManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// static メンバの定義
std::vector<ResultCSVManager::ResultRow> ResultCSVManager::result;

void ResultCSVManager::LoadResultCSV(const std::string& csvPath)
{
	std::ifstream file(csvPath);// 指定したファイル開く
	if (!file.is_open())
	{
		std::cerr << "failed to open CSV file:" << csvPath << std::endl;
		return;
	}

	std::string line;
	getline(file, line); // 一行目はスキップ

 	while (getline(file, line))//CSVから1行分を読み取ってlineに入れる getline=文字列取り出す関数
	{
		std::stringstream ss(line);//stringstream でその行(line)をさらにカンマで区切る
		ResultRow row;

		std::string OrderNoStr, BodyScoreStr, BeltScoreStr, BracersScoreStr, BootsScoreStr;

		std::getline(ss, OrderNoStr, ',');
		std::getline(ss, BodyScoreStr, ',');
		std::getline(ss, BeltScoreStr, ',');
		std::getline(ss, BracersScoreStr, ',');
		std::getline(ss, BootsScoreStr, ',');

		// 文字列→数値に変換　　 std::stoiでintに変換できる
		row.OrderNo = std::stoi(OrderNoStr);
		row.BodyGoalScore = std::stoi(BodyScoreStr);
		row.BeltGoalScore = std::stoi(BeltScoreStr);
		row.BracersGoalScore = std::stoi(BracersScoreStr);
		row.BootsGoalScore = std::stoi(BootsScoreStr);

		// CSVから読み込んだ１行分のデータを、全体のリストに追加する
		result.push_back(row); // rowをresultベクターの末尾に追加
	}
}
