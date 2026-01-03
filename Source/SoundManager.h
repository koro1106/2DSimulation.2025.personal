#pragma once
#include <map>
#include <string>
#include "DxLib.h"

class SoundManager
{
public:
	 static void LoadAll();
	 static void PlayBGM(const std::string& name);
	 static void PlaySE(const std::string& name);
	 static void StopBGM();
private:
	static std::map<std::string, int> bgm;
	static std::map<std::string, int> se;
	static std::string currentBGM; // åªç›ÇÃBGM
};