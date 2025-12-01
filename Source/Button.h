#pragma once
#include <string>
#include <vector>
#include <functional>

class Button
{
public:
	Button(int x, int y, int width, int height, const std::string& buttonID, int imageHandle = -1, std::function<void()> onClick = nullptr);
	bool IsMouseOver(int mouseX, int mouseY)const;
	void OnClick()const;
	void Draw()const;
	static void ButtonSystem(std::vector<Button>& buttons);
private:
	int x, y;
	int width, height;
	std::string buttonID;
	int imageHandle; // ボタンの画像ハンドル
	std::function<void()>onClickFunc; //ボタンがクリックされたときに実行される関数(関数を格納できる変数)
};