#pragma once
#include <string>

class Message
{
public:
	Message();
	void Update();
	void Draw(int x, int y, int color, int fontHandle);
	void SetText(const std::string& txt);
	bool IsFinished(); // 終了したか
private:
	std::string text; // 表示する文章
	int len;		  // 現在表示してる文字数
	int interval;     // 文字送り用タイマー
};