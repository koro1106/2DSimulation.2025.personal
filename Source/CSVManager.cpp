#include "CSVManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Library/SceneBase.h"
#include "OverlayManager.h"
//using namespace std;

std::map<std::string, std::map<std::string, std::string>> CSVManager::displayModes;
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
	getline(file, line);//Skip the first line

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string screenID, buttonID, nextScreen, displayMode;

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
	/*DebugLog("currentScene = " + currentScene);
	DebugLog("buttonID = " + buttonID);*/

	auto screenIt = transitions.find(currentScene);
	if (screenIt != transitions.end())
	{
		auto& buttonMap = screenIt->second;
		auto btnIt = buttonMap.find(buttonID);
		if (btnIt != buttonMap.end())
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

// Change Scene Or Overlay
void CSVManager::ChangeSceneOrOverlay(const std::string& currentScene, const std::string& buttonID)
{
	//1. currentScene & buttonID = nextScene Get
	auto nextScene = GetNextScene(currentScene, buttonID);
	if (nextScene.empty()) return; // If there is no next scene, exit the process.

	// 2. Get the "display mode" information of the current scene
	auto screenIt = displayModes.find(currentScene);
	if (screenIt != displayModes.end())
	{
		// 3.Get the display mode == Current scene button ID
		auto btnIt = screenIt->second.find(buttonID);
		if (btnIt != screenIt->second.end())
		{
			// 4.If display mode "overlay"
			if (btnIt->second == "overlay")
			{
				// 5. Show Overlay
				// If overlay display is used, the scene will not change.
				// For example, give a display instruction to the overlay management class
			    OverlayManager::ShowOverlay(nextScene);
				return;
			}
		}
	}
	// Otherwise, transition
	ChangeScene(nextScene);
}
