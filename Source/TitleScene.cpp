#include "TitleScene.h"
#include "ImageManager.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
	ImageManager::LoadAll();

	AddFontResourceEx("data/font/cinecaption226.ttf", FR_PRIVATE, NULL); // Windowsが一時的にフォント使えるようになる。インストール不要
	fontHandl = CreateFontToHandle("しねきゃぷしょん", 45, 0);

	SetMouseDispFlag(FALSE); //　OSのマウスカーソル消す
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	// マウス位置
	GetMousePoint(&mx, &my);

	t += 0.05f;             
	gearAngle += 0.4f; // 回転速度加算

	bool isMousePressed = (GetMouseInput() & MOUSE_INPUT_LEFT);
	//クリックした瞬間だけ
	if (isMousePressed && !prevButton)
	{
		SceneManager::ChangeScene("PLAY");
	}
	//前の入力を保存
	prevButton = isMousePressed;

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	// 背景
	DrawGraph(0, 0, ImageManager::Get("titleBG"), TRUE);
	// 歯車
	DrawRotaGraph(15, 390, 1.0f, gearAngle * DX_PI / 180.0f, ImageManager::Get("gear1"), TRUE);
	DrawRotaGraph(90, 70, 1.0f, -gearAngle * DX_PI / 180.0f, ImageManager::Get("gear2"), TRUE);
	DrawRotaGraph(1900, 780, 1.0f, gearAngle * DX_PI / 180.0f, ImageManager::Get("gear1"), TRUE);
	DrawRotaGraph(1700, 1050, 1.0f, -gearAngle * DX_PI / 180.0f, ImageManager::Get("gear2"), TRUE);

	// 1.  sin(t) * 0.5f  =  -1 ～ +1 の値を-0.5 ～ + 0.5 に狭める
    // 2. +0.5f = -0.5 ～ +0.5 の値を0 ～ 1 にずらす
    // 3. *255 = α値として使えるように 0～255 の整数に変換
	int alpha = (int)((sin(t) * 0.5f + 0.5f) * 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawFormatStringToHandle(750, 900, GetColor(200, 200, 200), fontHandl, "%s", "- Click to Start -");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// マウスカーソル
	DrawGraph(mx, my, ImageManager::Get("cursor"), TRUE);
}
