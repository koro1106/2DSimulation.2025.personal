#pragma once
#include <string>
#include <vector>
class ResultCSVManager
{
public:
	// CSV読み込み
	static void LoadResultCSV(const std::string& csvPath);

	struct ResultRow
	{
		int OrderNo = 0;			// お題番号
		int BodyGoalScore = 0;		// BodyのGoalスコア
		int BeltGoalScore = 0;		// BeltのGoalスコア
		int BracersGoalScore = 0;	// BracersのGoalスコア
		int BootsGoalScore = 0;		// BootsのGoalスコア
	};

	static std::vector<ResultRow> result;
};