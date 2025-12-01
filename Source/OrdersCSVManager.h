#pragma once
#include <string>
#include <vector>
class OrdersCSVManager
{
public:
	// CSV“Ç‚İ‚İ
	static void LoadOrdersCSV(const std::string& csvPath);
	struct OrderRow
	{
		std::string No;
		std::string order1;
		std::string order2;
		std::string order3;
		std::string order4;
	};
	static std::vector<OrderRow> orders; // vector‚ÉOrderRow‚Ìƒf[ƒ^’™‚ß‚é
};