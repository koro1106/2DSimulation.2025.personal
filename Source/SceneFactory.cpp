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
#include "ResultScene.h"

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
	
	assert(false);
	return nullptr;
}
