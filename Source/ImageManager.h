#pragma once
#include <string>
#include "DxLib.h"
#include <unordered_map>

class ImageManager {
public:
    static void LoadAll();  // 読み込み用
    static int Get(const std::string& name); // 取得用
private:
    static std::unordered_map<std::string, int> images;// static付けると中身残る（メモリリークとれない）
};