#include "CSVManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Library/SceneBase.h"
//using namespace std;

std::map<std::string, std::map<std::string, std::string>>CSVManager::transitions;
void DebugLog(const std::string& msg)
{
	OutputDebugStringA((msg + "\n").c_str());
}
void CSVManager::LoadSceneTransitions(const std::string& csvPath)
{
	std::ifstream file(csvPath);
	if (!file.is_open()) 
	{
		std::cerr << "failed to open CSV file:" << csvPath << std::endl;
		return;
	}
	std::string line;
	//Skip the first line
	getline(file, line);

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string screenID, buttonID, nextScreen;

		if(!std::getline(ss, screenID, ',')) continue;
		if (!std::getline(ss, buttonID, ',')) continue;
		if (!std::getline(ss, nextScreen, ',')) continue;
		DebugLog("Loaded: [" + screenID + "] | [" + buttonID + "] -> [" + nextScreen + "]");

		transitions[screenID][buttonID] = nextScreen;
	}
}

std::string CSVManager::GetNextScene(const std::string& currentScene, const std::string& buttonID)
{
	/*DebugLog("currentScene = " + currentScene);
	DebugLog("buttonID = " + buttonID);*/

	auto screenIt = transitions.find(currentScene);
	if (screenIt != transitions.end())
	{
		auto& buttonMap = screenIt->second;
		auto btnIt = buttonMap.find(buttonID);
		if (btnIt != buttonMap.end())
		{
			//DebugLog("Found nextScene = " + btnIt->second);
			return btnIt->second;
		}
	}
	//DebugLog("Not found, return empty");
	return "";


}

void CSVManager::ChangeScene(const std::string& sceneName)
{
	if (sceneName == "PLAY")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "TITLE")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "LIST")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "MANUAL")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "CAUTION")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "CLOTHES1")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "CLOTHES2")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "CLOTHES3")
	{
		SceneManager::ChangeScene(sceneName);
	}
	if (sceneName == "CLOTHES4")
	{
		SceneManager::ChangeScene(sceneName);
	}
	
}
