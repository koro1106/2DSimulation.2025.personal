#pragma once
#include <DxLib.h>
class Light
{
public:
	Light(int x, int y, int radius, int color = GetColor(255,255,180), int intensity = 255)
		:centerX(x), centerY(y), radius(radius), color(color), intensity(intensity){ }
	void Draw();
private:
	int centerX, centerY; // Œõ‚Ì’†SÀ•W
	int radius;           // Œõ‚Ì”¼Œa
	int color;           // Œõ‚ÌF
	int intensity;           // Œõ‚Ì–¾‚é‚³
};

