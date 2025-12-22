#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 
#include "ResultCSVManager.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	~ResultScene();
	void Update() override;
	void Draw() override;
	
	struct DisplayResult {
	int OrderNo;
	int TotalDiff;
	std::string Rank;
	DisplayResult(int o, int t, const std::string& r)
		: OrderNo(o), TotalDiff(t),Rank(r){}
    };

private:
	int TotalDiff(const ResultCSVManager::ResultRow& row);
	std::vector<DisplayResult> displayResult; // 計算した結果一覧
	std::vector<Button> buttons;
	int fontHandl;
	std::string rank;

	bool isNext = false; // 次の業務へ行けるか
	int back; // 戻る画像
	int next; // 進む画像

	void RefreshButtons(); // 初期状態のボタン
};