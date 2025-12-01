#include "OverlayManager.h"

// 静的変数の実体定義
bool OverlayManager::isOverlayVisible = false;  
bool OverlayManager::overlayJustOpened = false;  
bool OverlayManager::playedAnimation = false;  
ClothesScene1 OverlayManager::clothes1_Overlay; 
ClothesScene2 OverlayManager::clothes2_Overlay;
ClothesScene3 OverlayManager::clothes3_Overlay;
ClothesScene4 OverlayManager::clothes4_Overlay;
ListScene OverlayManager::listScene_Overlay;
ManualScene OverlayManager::manualScene_Overlay;
ResultScene OverlayManager::resultScene_Overlay;
ResultCheck OverlayManager::resultCheck_Overlay;

std::string OverlayManager::currentOverlay = ""; 

void OverlayManager::ShowOverlay(const std::string& overlayName)
{
	bool wasVisible = isOverlayVisible; // すでにオーバーレイが開いているか判定

	isOverlayVisible = true;
	currentOverlay = overlayName;
	
	// すでにオーバーレイが開いているならアニメーション再生しない
	if (!wasVisible)
	{
		overlayJustOpened = true; // 初回だけアニメ再生
	}
	else
	{
		overlayJustOpened = false; // ページ切り替え時は再生しない
	}

	if (overlayName == "CLOTHES1") {
		clothes1_Overlay = ClothesScene1();
	}
	if (overlayName == "CLOTHES2") {
		clothes2_Overlay = ClothesScene2();
	}
	if (overlayName == "CLOTHES3") {
		clothes3_Overlay = ClothesScene3();
	}
	if (overlayName == "CLOTHES4") {
		clothes4_Overlay = ClothesScene4();
	}
	if (overlayName == "LIST") {
		listScene_Overlay = ListScene();
	}
	if (overlayName == "MANUAL") {
		manualScene_Overlay = ManualScene();
	}
	if (overlayName == "RESULT") {
		resultScene_Overlay = ResultScene();
	}
	if (overlayName == "RESULTCHECK") {
		resultCheck_Overlay = ResultCheck();
	}
}

void OverlayManager::HideOverlay()
{
	isOverlayVisible = false; // 非表示状態に戻す
	currentOverlay = "";      // 現在のオーバーレイ名をクリア
	overlayJustOpened = false; // 今閉じているので「開いた直後」ではない
	playedAnimation = false; // 閉じたら次回再生できるようにfalseにする
}
void OverlayManager::Update()
{
	if (!isOverlayVisible) return;

	if (currentOverlay == "CLOTHES1")
	{
		clothes1_Overlay.Update();
	}
	if (currentOverlay == "CLOTHES2")
	{
		clothes2_Overlay.Update();
	}
	if (currentOverlay == "CLOTHES3")
	{
		clothes3_Overlay.Update();
	}
	if (currentOverlay == "CLOTHES4")
	{
		clothes4_Overlay.Update();
	}
	if (currentOverlay == "LIST")
	{
		listScene_Overlay.Update();
	}
	if (currentOverlay == "MANUAL")
	{
		manualScene_Overlay.Update();
	}
	if (currentOverlay == "RESULT")
	{
		resultScene_Overlay.Update();
	}
	if (currentOverlay == "RESULTCHECK")
	{
		resultCheck_Overlay.Update();
	}
}
void OverlayManager::Draw()
{
	if (!isOverlayVisible) return;
	
	// BackGround Black
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 0, 1920, 1080, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (currentOverlay == "CLOTHES1")
	{
		clothes1_Overlay.Draw(); 
	}
	if (currentOverlay == "CLOTHES2")
	{
		clothes2_Overlay.Draw(); 
	}
	if (currentOverlay == "CLOTHES3")
	{
		clothes3_Overlay.Draw(); 
	}
	if (currentOverlay == "CLOTHES4")
	{
		clothes4_Overlay.Draw(); 
	}
	if (currentOverlay == "LIST")
	{
		listScene_Overlay.Draw();
	}
	if (currentOverlay == "MANUAL")
	{
		manualScene_Overlay.Draw();
	}
	if (currentOverlay == "RESULT")
	{
		resultScene_Overlay.Draw();
	}
	if (currentOverlay == "RESULTCHECK")
	{
		resultCheck_Overlay.Draw();
	}
}
