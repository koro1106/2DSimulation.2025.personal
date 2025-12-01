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
	std::vector<DisplayResult> displayResult; // ŒvŽZ‚µ‚½Œ‹‰Êˆê——
	std::vector<Button> buttons;
	int fontHandl;
	std::string rank;
};