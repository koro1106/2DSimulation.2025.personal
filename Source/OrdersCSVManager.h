#pragma once
#include <string>
#include <vector>
class OrdersCSVManager
{
public:
	// CSV読み込み
	static void LoadOrdersCSV(const std::string& csvPath);
	struct OrderRow
	{
		std::string No;
		std::string order1;
		std::string order2;
		std::string order3;
		std::string order4;
	};
	static std::vector<OrderRow> orders; // vectorにOrderRowのデータ貯める
	static int currentOrderIndex; // 今表示してるCSVの行
};