#pragma once
#include <vector>
#include "ImageManager.h"
#include <functional>
class OverlayPart
{
public:
	int imageID;
	float currentX, currentY; //現在位置
	float startX, startY;     // スタート位置
	float targetX, targetY;   // 目標位置
	float speed;
	bool finished;

	//初期化
	OverlayPart(int id, float stX, float stY, float tX, float tY, float spd)
		:imageID(id),startX(stX),startY(stY),currentX(stX),currentY(stY),targetX(tX), targetY(tY),speed(spd),finished(false){ }
	
	void Update();
	void Draw();

};

class OverlayAnimation {
public:
	OverlayPart backGround; // 背景のアニメーション
	std::vector<OverlayPart> parts; // 装備パーツのアニメーション

	// コンストラクタ
	OverlayAnimation()
		: backGround(-1, 0, 0, 0, 0, 0.0f) {
	}
	OverlayAnimation(int imageHandle)
		: backGround(imageHandle, 70, -720, 70, 125, 0.2f) {} // (画像,初期座標,目標座標,スピード)
	
	void Update();
	void Draw();
	bool IsFinished();

	// パーツを追加(各装備)
	void AddPart(int imageHandle, float stX, float stY, float tX, float tY, float speed) {
		parts.push_back(OverlayPart(imageHandle, stX, stY, tX, tY, speed));// (画像、初期位置、目標位置、スピード)
	}

};