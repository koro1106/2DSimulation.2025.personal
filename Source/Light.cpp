#include <DxLib.h>
#include "Light.h"

void Light::Draw()
{
	//　加算合成開始
	SetDrawBlendMode(DX_BLENDMODE_ADD, intensity);
	//グラデーションっぽく光を描く
	for (int r = radius; r > 0; r -= 10)
	{
		int alpha = (r * 128) / radius;// 最大128（半透明）に抑える
		SetDrawBlendMode(DX_BLENDMODE_ADD, alpha / 2);
		DrawCircle(centerX, centerY, r, color, TRUE);
	}
	//ブレンド解除
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}