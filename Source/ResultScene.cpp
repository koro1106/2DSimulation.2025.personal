#include "ResultScene.h"
#include "ImageManager.h"
#include "OverlayManager.h"
#include "ResultCSVManager.h"
#include "OrdersCSVManager.h"
#include "ClothesData.h"

ResultScene::ResultScene()
{
	ImageManager::LoadAll();
	back = ImageManager::Get("resultBack");
	next = ImageManager::Get("resultNext");

	RefreshButtons(); // 初期状態のボタン
}

ResultScene::~ResultScene()
{
}
void ResultScene::Update()
{
	displayResult.clear();

	// 今表示している行だけを見る
	int idx = ResultCSVManager::currentOrderIndex;
	if (idx < 0 || idx >= ResultCSVManager::result.size()) return;

	const auto& row = ResultCSVManager::result[idx];

	int totalDiff = TotalDiff(row);
	
	// Great以上は次の業務へ行ける
	if (totalDiff == 0) {
		rank = "Perfect";
		isNext = true;
	}
	else if (totalDiff <= 2) {
		rank = "Great";
		isNext = true;
	}
	else if (totalDiff <= 4) {
		rank = "Nice";
		isNext = false;
	}
	else {
		rank = "Miss";			
		isNext = false;
	}
	
	// isNext が前のフレームから変わった瞬間だけ、ボタンを作り直す
	static bool prevIsNext = false;
	if (isNext != prevIsNext) {
		RefreshButtons();
		prevIsNext = isNext;
	}

	Button::ButtonSystem(buttons);
}
void ResultScene::Draw()
{
	DrawGraph(200, 150, ImageManager::Get("resultBG"), TRUE); // 背景

	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	// ランクに応じて画像表示
	if (rank == "Perfect")
		DrawGraph(600, 500, ImageManager::Get("result_Perfect"), TRUE);
	else if (rank == "Great")
		DrawGraph(600, 500, ImageManager::Get("result_Great"), TRUE);
	else if (rank == "Nice")
		DrawGraph(600, 500, ImageManager::Get("result_Nice"), TRUE);
	else if (rank == "Miss")
		DrawGraph(600, 500, ImageManager::Get("result_Miss"), TRUE);
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

void ResultScene::RefreshButtons()
{
	buttons.clear();

	if (isNext)
	{
		// Next だけ表示
		buttons.emplace_back(
			1000, 1000, 217, 74, "ResultNext", next,
			[]() {
				if (OrdersCSVManager::currentOrderIndex + 1 < OrdersCSVManager::orders.size())
					OrdersCSVManager::currentOrderIndex++; // 次の行へ進める

				if (ResultCSVManager::currentOrderIndex + 1 < ResultCSVManager::result.size())
					ResultCSVManager::currentOrderIndex++; // 次の行へ進める

				OverlayManager::HideOverlay();
			}
		);
	}
	else
	{
		// Back だけ表示
		buttons.emplace_back(
			570, 1000, 217, 74, "ResultBack", back,
			[]() {
				OverlayManager::HideOverlay();
			}
		);
	}
}
