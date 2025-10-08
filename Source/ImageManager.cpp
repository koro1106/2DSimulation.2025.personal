#include "ImageManager.h"

std::map<std::string, int> ImageManager::images;

void ImageManager::LoadAll()
{
    images["back"] = LoadGraph("data/image/Art/back.png");

    //BackGround
    images["bg1"] = LoadGraph("data/image/Art/BackGround1.png");
    images["bg2"] = LoadGraph("data/image/Art/BackGround2.png");
    images["bg4"] = LoadGraph("data/image/Art/BackGround4.png");//wear bg

    //PlaySceneUI
    images["exit"] = LoadGraph("data/image/Art/exit.png");
    images["list"] = LoadGraph("data/image/Art/list.png");
    images["door"] = LoadGraph("data/image/Art/door.png");
    images["hatena"] = LoadGraph("data/image/Art/hatena.png");
    images["book"] = LoadGraph("data/image/Art/book.png");
    images["human"] = LoadGraph("data/image/Art/human.png");
    images["meter"] = LoadGraph("data/image/Art/meter.png");

    //Clothes
    images["clothes1"] = LoadGraph("data/image/Art/clothes1.png");
    images["clothes2"] = LoadGraph("data/image/Art/clothes2.png");
    images["clothes3"] = LoadGraph("data/image/Art/clothes3.png");
    images["clothes4"] = LoadGraph("data/image/Art/clothes4.png");

    images["attack"] = LoadGraph("data/image/Art/attack.png");
    images["defense"] = LoadGraph("data/image/Art/defense.png");
    images["kindness"] = LoadGraph("data/image/Art/kindness.png");
    images["humor"] = LoadGraph("data/image/Art/humor.png");


    images["+1"] = LoadGraph("data/image/Art/+1.png");// next
    images["-1"] = LoadGraph("data/image/Art/-1.png");// back


    //ListScene
    images["listBg"] = LoadGraph("data/image/Art/ListScene.png");
}

int ImageManager::Get(const std::string& name)
{
    return images[name];
}
