#include "ResultScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "ResultCSVManager.h"
#include "ClothesData.h"

ResultScene::ResultScene()
{
	
}

ResultScene::~ResultScene()
{
}
void ResultScene::Update()
{
	displayResult.clear();

	for (const auto& row : ResultCSVManager::result)
	{
		int totalDiff = TotalDiff(row);

		if (totalDiff == 0) rank = "S";
		else if (totalDiff <= 2) rank = "A";
		else if (totalDiff <= 4) rank = "B";
		else rank = "C";
	}
}
void ResultScene::Draw()
{
	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	// ランクに応じて画像表示
	if (rank == "S")
		DrawGraph(600, 500, ImageManager::Get("result_S"), TRUE);
	else if(rank == "A")
		DrawGraph(600, 500, ImageManager::Get("result_A"), TRUE);
	else if(rank == "B")
		DrawGraph(600, 500, ImageManager::Get("result_B"), TRUE);
	else if(rank == "C")
		DrawGraph(600, 500, ImageManager::Get("result_C"), TRUE);
}

// 装備とゴールの値の差を計算
int ResultScene::TotalDiff(const ResultCSVManager::ResultRow& row)
{
	int armorScore = ClothesData::GetArmorScore();
	int beltScore = ClothesData::GetBeltScore();
	int bracersScore = ClothesData::GetBracersScore();
	int bootsScore = ClothesData::GetBootsScore();

	return
		abs(armorScore - row.BodyGoalScore) +
		abs(beltScore - row.BeltGoalScore) +
		abs(bracersScore - row.BracersGoalScore) +
		abs(bootsScore - row.BootsGoalScore);
}
