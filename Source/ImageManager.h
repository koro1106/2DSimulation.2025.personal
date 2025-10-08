#pragma once
#include <map>
#include <string>
#include "DxLib.h"

class ImageManager {
public:
    static void LoadAll();
    static int Get(const std::string& name);

private:
    static std::map<std::string, int> images;
};