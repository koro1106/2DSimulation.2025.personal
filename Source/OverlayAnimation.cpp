#include "OverlayAnimation.h"
#include <DxLib.h>

void OverlayPart::Update()
{
	if (finished) return;
	//現在座標と目標座標の差分で目標位置に近づける
	currentX += (targetX - currentX) * speed;
	currentY += (targetY - currentY) * speed;

	if (abs(targetX - currentX) < 1.0f && abs(targetY - currentY) < 1.0f)// 現在位置 - 目標位置 = 1未満で終了
	{
		currentX = targetX;
		currentY = targetY;
		finished = true;
	}
}
void OverlayPart::Draw()
{
	DrawGraph((int)currentX, (int)currentY, imageID, TRUE);
}


//　アニメーション
void OverlayAnimation::Update()
{
	backGround.Update();

	//　装備パーツも更新
	for (auto& part : parts)//partsの中の各要素を参照で受け取り、順番に処理
	{
		part.Update();
	}
}
void OverlayAnimation::Draw()
{
	backGround.Draw();

	//　装備パーツも描画
	for (auto& part : parts)
	{
		part.Draw();
	}
}
bool OverlayAnimation::IsFinished()
{
	if (!backGround.finished) return false;

	for (auto& part : parts)
	{
		if (!part.finished) return false;
	}

	return true;
}
