#pragma once
#include "../Library/SceneBase.h"
#include "Button.h"
#include <vector> 
#include "OverlayAnimation.h"

class ClothesScene1 : public SceneBase
{
public:
	ClothesScene1();
	~ClothesScene1();
	void Update() override;
	void Draw() override;
	bool isInitialized = false; // 初期化されたか
	//背景アニメーション
	void StartBackgroundAnimation(float tx, float ty);
private:
	std::vector<Button> buttons;
	std::string Utf8ToSjis(const std::string& src);
	OverlayAnimation overlayAnim;
	int fontHandl;
	// 背景アニメーション用
	float bgX = 70;   // 最初は画面外に置く
	float bgY = -800;
	float bgTargetX, bgTargetY ;
	bool bgAnimFinished = true;
};