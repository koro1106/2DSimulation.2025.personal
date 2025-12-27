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

	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 30, 0);
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
	DrawGraph(410, 250, ImageManager::Get("resultBG"), TRUE); // 背景

	//ボタン描画
	for (const auto& button : buttons)
	{
		button.Draw();
	}

	// ランクに応じて画像表示
	if (rank == "Perfect") {
		DrawGraph(800, 450, ImageManager::Get("result_Perfect"), TRUE);
		DrawFormatStringToHandle(780, 610, GetColor(180, 160, 0), fontHandl, "素晴らしい！完璧ですね");
	}
	else if (rank == "Great") {
		DrawGraph(800, 450, ImageManager::Get("result_Great"), TRUE);
		DrawFormatStringToHandle(700, 610, GetColor(180, 160, 0), fontHandl, "いい感じです。このまま頑張りましょう");
	}
	else if (rank == "Nice") {
		DrawGraph(800, 450, ImageManager::Get("result_Nice"), TRUE);
		DrawFormatStringToHandle(770, 610, GetColor(180, 160, 0), fontHandl, "もう少し頑張りましょう");
	}
	else if (rank == "Miss") {
		DrawGraph(800, 450, ImageManager::Get("result_Miss"), TRUE);
		DrawFormatStringToHandle(750, 610, GetColor(180, 160, 0), fontHandl, "発注リストをよく見ましょう");
	}
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
			850, 700, 217, 74, "ResultNext", next,
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
			850, 700, 217, 74, "ResultBack", back,
			[]() {
				OverlayManager::HideOverlay();
			}
		);
	}
}
