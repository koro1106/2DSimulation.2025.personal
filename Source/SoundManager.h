#pragma once
#include <unordered_map>
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
	static std::unordered_map<std::string, int> bgm;
	static std::unordered_map<std::string, int> se;
	static std::string currentBGM; // åªç›ÇÃBGM
};