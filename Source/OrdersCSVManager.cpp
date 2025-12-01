#include "OrdersCSVManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "ButtonPosCSVManager.h"
#include "ClothesData.h"

// static変数の定義
std::vector<OrdersCSVManager::OrderRow> OrdersCSVManager::orders;

void OrdersCSVManager::LoadOrdersCSV(const std::string& csvPath)
{
	std::ifstream file(csvPath);// 指定したファイル開く
	if (!file.is_open())
	{
		std::cerr << "failed to open CSV file:" << csvPath << std::endl;
		return;
	}

	std::string line;
	getline(file, line); // 一行目はスキップ

	while (getline(file, line))//CSVから1行分を読み取ってlineに入れる
	{
		std::stringstream ss(line);//stringstream でその行(line)をさらにカンマで区切る
		std::string No, order1, order2, order3, order4;
	
		std::getline(ss, No, ',');
		std::getline(ss, order1, ',');
		std::getline(ss, order2, ',');
		std::getline(ss, order3, ',');
		std::getline(ss, order4, ',');

		// UTF-8 → Shift-JIS変換
		std::string order1JIS = ClothesData::Utf8ToSjis(order1);
		std::string order2JIS = ClothesData::Utf8ToSjis(order2);
		std::string order3JIS = ClothesData::Utf8ToSjis(order3);
		std::string order4JIS = ClothesData::Utf8ToSjis(order4);

		// 保存する
		OrderRow row;
		row.No = No;
		row.order1 = order1JIS;
		row.order2 = order2JIS;
		row.order3 = order3JIS;
		row.order4 = order4JIS;

		orders.push_back(row); // vectorの末尾に要素追加
	}
}
