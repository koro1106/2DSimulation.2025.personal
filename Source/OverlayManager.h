#pragma once
#include <string>
#include "ClothesScene1.h"
#include "ClothesScene2.h"
#include "ClothesScene3.h"
#include "ClothesScene4.h"
#include "ListScene.h"
#include "ManualScene.h"
#include "ResultScene.h"
#include "ResultCheck.h"
#include "DxLib.h"
class OverlayManager 
{
public:
	// オーバーレイ用のシーンのインスタンス化
	static ClothesScene1 clothes1_Overlay; 
	static ClothesScene2 clothes2_Overlay; 
	static ClothesScene3 clothes3_Overlay; 
	static ClothesScene4 clothes4_Overlay; 
	static ListScene listScene_Overlay; 
	static ManualScene manualScene_Overlay; 
	static ResultScene resultScene_Overlay; 
	static ResultCheck resultCheck_Overlay;

	static bool isOverlayVisible; // オーバーレイフラグ
	static bool overlayJustOpened; // 初回再生判定フラグ
	static bool playedAnimation;  // アニメーション再生済みか
	static std::string currentOverlay;

	static void ShowOverlay(const std::string& overlayName);
	static void HideOverlay();
	static void Update();
	static void Draw();
};