#pragma once
#include "Button.h"

class ResultCheck
{
public:
	ResultCheck();
	~ResultCheck();
	void Update();
	void Draw();

private:
	std::vector<Button> buttons;
	int fontHandl;
};
