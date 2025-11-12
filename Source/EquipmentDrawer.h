#pragma once
#include "DxLib.h"
#include "ClothesData.h"

/// <summary>
/// 選択中の装備を描画するクラス
/// </summary>

enum class EquipmentType
{
	Armor,
	Belt,
	Bracers,
	Boot
};

class EquipmentDrawer
{
public:
	// 選択中の装備描画
	static void DrawSelectedEquipment(EquipmentType type);
};
