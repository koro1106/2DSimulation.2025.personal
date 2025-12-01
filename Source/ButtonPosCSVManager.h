#pragma once
#include <string>
#include <vector>
/// <summary>
/// 装備ボタンの座標CSV読み取りクラス
/// </summary>
class ButtonPosCSVManager
{
public:
	// CSV読み込み
	static void LoadPositionsCSV(const std::string& csvPath);

	struct ButtonPos 
	{
		int backButtonX;
        int backNextButtonY;
        int nextButtonX;
        int sceneBackButtonX;
        int sceneBackButtonY;
        int clothes1X;
        int clothes2X;
        int clothes3X;
        int clothes4X;
        int clothes5X;
        int clothesButtonY;
	};
    static ButtonPos pos;
    static std::vector<ButtonPos> positions;

    enum ButtonNo
    {
      ButtonNo_1,
      ButtonNo_2,
      ButtonNo_3,
      ButtonNo_4,
      ButtonNo_5,
    };
    //std::pair<int, int> は2つの値をまとめて持てる型
    static std::pair<int, int> GetButtonPosition(ButtonNo no);
};