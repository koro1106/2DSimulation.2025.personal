#pragma once
#include <string>
#include <vector>
//using namespace std;

class Button
{
private:
	int x, y;
	int width, height;
	std::string buttonID;
	int imageHandle;//Image Handle for the button image

public:
	Button(int x, int y, int width, int height, const std::string& buttonID, int imageHandle = -1);
	bool IsMouseOver(int mouseX, int mouseY)const;
	void OnClick()const;
	void Draw()const;
	static void ButtonSystem(std::vector<Button>& buttons);
};