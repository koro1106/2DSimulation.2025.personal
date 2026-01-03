#include "App.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Time.h"
#include "../Source/CSVManager.h"
#include "../Source/EquipmentsCSVManager.h"
#include <DxLib.h>
#include "../Source/ResultCSVManager.h"
#include "../Source/ButtonPosCSVManager.h"
#include "../Source/OrdersCSVManager.h"
#include "../Source/SoundManager.h"
#include "../Source/ImageManager.h"
void AppInit()
{
	ObjectManager::Init();
	SceneManager::Init();
	Time::Init();
	CSVManager::LoadSceneTransitions("SceneManager.csv");
	EquipmentCSVManager::LoadEquipmentsCSV("Equipments.csv");
	ResultCSVManager::LoadResultCSV("Result.csv");
	ButtonPosCSVManager::LoadPositionsCSV("ButtonPosition.csv");
	OrdersCSVManager::LoadOrdersCSV("Orders.csv");
	ImageManager::LoadAll();
	SoundManager::LoadAll();
}

void AppUpdate()
{
	SceneManager::Update();
	ObjectManager::Update();
}

void AppDraw()
{
	Time::Refresh();
	ObjectManager::Draw();
	SceneManager::Draw();
}

void AppRelease()
{
	Time::Release();
	SceneManager::Release();
	ObjectManager::Release();
}

bool AppIsExit()
{
	return SceneManager::IsExit();
}