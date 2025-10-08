#pragma once
#include <string>
#include <map>
//using namespace std;

class CSVManager
{
public:
	//CSV Load
	static void LoadSceneTransitions(const std::string& csvPath);

	//Get the destination scene name from the current scene name and button ID
	static std::string GetNextScene(const std::string& currentScene, const std::string& buttonID);

	//Scene Change
	static void ChangeScene(const std::string& sceneName);

private:
	//key: currentSceneName, value:(key:buttonID,value:destinationScene)
	static std::map<std::string, std::map<std::string, std::string>> transitions;
};