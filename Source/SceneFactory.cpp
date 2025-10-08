#include "SceneFactory.h"
#include <windows.h>
#include <assert.h>
#include "BootScene.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ListScene.h"
#include "ManualScene.h"
#include "CautionScene.h"
#include "ClothesScene1.h"
#include "ClothesScene2.h"
#include "ClothesScene3.h"
#include "ClothesScene4.h"

SceneBase* SceneFactory::CreateFirst()
{
	return new BootScene();
}

SceneBase * SceneFactory::Create(const std::string & name)
{
	if (name == "TITLE")
	{
		return new TitleScene();
	}
	if (name == "PLAY")
	{
		return new PlayScene();
	}
	if (name == "LIST")
	{
		return new ListScene();
	}
	if (name == "MANUAL")
	{
		return new ManualScene();
	}
	if (name == "CAUTION")
	{
		return new CautionScene();
	}
	if (name == "CLOTHES1")
	{
		return new ClothesScene1();
	}
	if (name == "CLOTHES2")
	{
		return new ClothesScene2();
	}
	if (name == "CLOTHES3")
	{
		return new ClothesScene3();
	}
	if (name == "CLOTHES4")
	{
		return new ClothesScene4();
	}
	
	assert(false);
	return nullptr;
}
