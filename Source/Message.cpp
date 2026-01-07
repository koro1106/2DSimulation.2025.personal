#include "Message.h"
#include <DxLib.h>

Message::Message()
{
	text = "";
	len = 0;
	interval = 0;
}

void Message::Update()
{
	if (len >= text.size()) return;

	if (interval > 0) {
		interval--;
		return;
	}

	// 全角・半角判定
	unsigned char c = text[len];
	if (c <= 0x7F) {
		len += 1; // 半角
	}
	else {
		len += 2; // 全角
	}
	interval = 3; // 文字速度（小さいほど速くなる）
}

void Message::Draw(int x, int y, int color, int fontHandle)
{
	std::string drawText = text.substr(0, len); // substr(開始位置,取り出す長さ)
	//DrawStringToHandle(x, y, drawText.c_str(), color, fontHandle);
	DrawFormatStringToHandle(x, y,color,fontHandle,"%s",drawText.c_str());
}

void Message::SetText(const std::string& txt)
{
	text = txt;
	len = 0;
	interval = 0;
}

bool Message::IsFinished()
{
	return len >= text.size(); // もう新しく取り出せる文字がないときtrue返す
}
