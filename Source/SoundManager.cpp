#include "SoundManager.h"
#include <cassert>

std::map<std::string, int > SoundManager::bgm;
std::map<std::string, int > SoundManager::se;
std::string SoundManager::currentBGM = "";

void SoundManager::LoadAll()
{
	// BGM 
	bgm["titleBGM"] = LoadSoundMem("data/sound/BGM/TitleBGM.mp3");
	bgm["playSceneBGM"] = LoadSoundMem("data/sound/BGM/PlaySceneBGM.mp3");

	// SE
	se["startSE"] = LoadSoundMem("data/sound/SE/StartClick.mp3");
	se["click"] = LoadSoundMem("data/sound/SE/Click.mp3");
	se["clickBack"] = LoadSoundMem("data/sound/SE/ClickBack.mp3");
	se["equipmentClick"] = LoadSoundMem("data/sound/SE/EquipmentChangeClick.mp3");
	se["opneList"] = LoadSoundMem("data/sound/SE/OpneList.mp3");
	se["result"] = LoadSoundMem("data/sound/SE/Result.mp3");
}

void SoundManager::PlayBGM(const std::string& name)
{
	if (currentBGM == name) return; // “¯‚¶BGM‚ª—¬‚ê‚Ä‚¢‚½‚ç‰½‚à‚µ‚È‚¢

	StopBGM(); // ¡—¬‚ê‚Ä‚éBGM‚ª‚ ‚ê‚Î~‚ß‚éi“ñd‚ÉÄ¶‚³‚ê‚é‚Ì‚ğ–h~j
	PlaySoundMem(bgm[name], DX_PLAYTYPE_LOOP); // ƒ‹[ƒvÄ¶
	currentBGM = name;
}

void SoundManager::PlaySE(const std::string& name)
{
	// SEÄ¶
	PlaySoundMem(se[name], DX_PLAYTYPE_BACK);
}

void SoundManager::StopBGM()
{
	// BGM~‚ß‚é
	if (!currentBGM.empty())
	{
		StopSoundMem(bgm[currentBGM]);
		currentBGM.clear();
	}
}
