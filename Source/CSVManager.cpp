#include "CSVManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Library/SceneBase.h"
#include "OverlayManager.h"

std::map<std::string, std::map<std::string, std::string>> CSVManager::displayModes;
std::map<std::string, std::map<std::string, std::string>>CSVManager::transitions;
void DebugLog(const std::string& msg)
{
	OutputDebugStringA((msg + "\n").c_str());
}
void CSVManager::LoadSceneTransitions(const std::string& csvPath)
{
	std::ifstream file(csvPath);// 指定したファイル開く
	if (!file.is_open()) 
	{
		std::cerr << "failed to open CSV file:" << csvPath << std::endl;
		return;
	}
	std::string line;
	getline(file, line);// 一行目はスキップ

	while (getline(file, line))
	{
		std::stringstream ss(line); //stringstream でその行(line)をさらにカンマで区切る
		std::string screenID, buttonID, nextScreen, displayMode;

		// getkine = 1行分の文字列を読み取る関数 
		// 読み込めなかったら無視して次の行に行く
		if(!std::getline(ss, screenID, ',')) continue;
		if (!std::getline(ss, buttonID, ',')) continue;
		if (!std::getline(ss, nextScreen, ',')) continue;
		if (!std::getline(ss, displayMode, ',')) continue;
		DebugLog("Loaded: [" + screenID + "] | [" + buttonID + "] -> [" + nextScreen + "] Mode:" + displayMode);

		transitions[screenID][buttonID] = nextScreen;
		displayModes[screenID][buttonID] = displayMode;
	}
}

std::string CSVManager::GetNextScene(const std::string& currentScene, const std::string& buttonID)
{
	//現在シーンの遷移情報を取得
	auto screenIt = transitions.find(currentScene);
	if (screenIt != transitions.end())// 見つかった場合だけ処理
	{
		//ボタンID に対応する遷移先を取得
		auto& buttonMap = screenIt->second;
		auto btnIt = buttonMap.find(buttonID);
		if (btnIt != buttonMap.end())// 見つかった場合だけ処理
		{
			return btnIt->second;
		}
	}
	return "";
}

void CSVManager::ChangeScene(const std::string& sceneName)
{
	SceneManager::ChangeScene(sceneName);
}

// シーン変えるかオーバーレイか
void CSVManager::ChangeSceneOrOverlay(const std::string& currentScene, const std::string& buttonID)
{
	//1. 現在のシーン＋ボタンのID で次のシーン取得
	auto nextScene = GetNextScene(currentScene, buttonID);
	if (nextScene.empty()) return; // 次のシーンなかったらreturn

	// 2. 現在のシーンの表示モードを取得
	auto screenIt = displayModes.find(currentScene);
	if (screenIt != displayModes.end())
	{
		// 3.ボタンIDに対応する表示モードを取得
		auto btnIt = screenIt->second.find(buttonID);
		if (btnIt != screenIt->second.end())
		{
			// 4.オーバーレイ表示か判定
			if (btnIt->second == "overlay")
			{
				// 5.表示モードが "overlay" ならオーバーレイ表示
			    OverlayManager::ShowOverlay(nextScene);
				return;
			}
		}
	}
	// それ以外の場合はシーン遷移
	ChangeScene(nextScene);
}
