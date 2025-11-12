#include "ImageManager.h"

std::map<std::string, int> ImageManager::images;

void ImageManager::LoadAll()
{
    images["back"] = LoadGraph("data/image/Art/back.png");
    //TextImage
    images["listText"] = LoadGraph("data/image/Art/listText.png");
    images["titleText"] = LoadGraph("data/image/Art/titleText.png");
    images["manualText"] = LoadGraph("data/image/Art/manualText.png");

    //BackGround
    images["bg1"] = LoadGraph("data/image/Art/BackGround5.png");
    images["bg2"] = LoadGraph("data/image/Art/BackGround2.png");
    images["bg4"] = LoadGraph("data/image/Art/BackGround4.png");//wear bg
    images["bg5"] = LoadGraph("data/image/Art/t23.png");
    images["bgList"] = LoadGraph("data/image/Art/t24.png");
    images["optionBG"] = LoadGraph("data/image/Art/t25.png");

    //PlaySceneUI
    images["cursor"] = LoadGraph("data/image/Art/cursor.png"); // ÉJÅ[É\ÉãâÊëú
    images["exit"] = LoadGraph("data/image/Art/exit.png");
    images["list"] = LoadGraph("data/image/Art/list.png");
    images["setting"] = LoadGraph("data/image/Art/setting.png");
    images["hatena"] = LoadGraph("data/image/Art/hatena.png");
    images["book"] = LoadGraph("data/image/Art/book.png");
    images["human"] = LoadGraph("data/image/Art/human.png");
    images["h1"] = LoadGraph("data/image/Art/h1.png");
    images["meter"] = LoadGraph("data/image/Art/meter.png");

    images["namePlate"] = LoadGraph("data/image/Art/t17.png");

    //ListScene
    images["listScene"] = LoadGraph("data/image/Art/ListScene.png");
  //ëïîı
    //BodyArmor
    images["BodyArmor1"] = LoadGraph("data/image/Icons/BodyArmor/BodyArmor_1.png");
    images["BodyArmor2"] = LoadGraph("data/image/Icons/BodyArmor/BodyArmor_10.png");
    images["BodyArmor3"] = LoadGraph("data/image/Icons/BodyArmor/BodyArmor_3.png");
    images["BodyArmor4"] = LoadGraph("data/image/Icons/BodyArmor/BodyArmor_4.png");
    images["BodyArmor5"] = LoadGraph("data/image/Icons/BodyArmor/BodyArmor_5.png");
    //Belt
    images["Belt1"] = LoadGraph("data/image/Icons/Belts/Belt_1.png");
    images["Belt2"] = LoadGraph("data/image/Icons/Belts/Belt_3.png");
    images["Belt3"] = LoadGraph("data/image/Icons/Belts/Belt_4.png");
    images["Belt4"] = LoadGraph("data/image/Icons/Belts/Belt_5.png");
    images["Belt5"] = LoadGraph("data/image/Icons/Belts/Belt_7.png");
    //Bracers
    images["Bracers1"] = LoadGraph("data/image/Icons/Bracers/Bracers_1.png");
    images["Bracers2"] = LoadGraph("data/image/Icons/Bracers/Bracers_2.png");
    images["Bracers3"] = LoadGraph("data/image/Icons/Bracers/Bracers_4.png");
    images["Bracers4"] = LoadGraph("data/image/Icons/Bracers/Bracers_5.png");
    images["Bracers5"] = LoadGraph("data/image/Icons/Bracers/Bracers_8.png");
    //Boots
    images["Boots1"] = LoadGraph("data/image/Icons/Boots/Boots_2.png");
    images["Boots2"] = LoadGraph("data/image/Icons/Boots/Boots_4.png");
    images["Boots3"] = LoadGraph("data/image/Icons/Boots/Boots_8.png");
    images["Boots4"] = LoadGraph("data/image/Icons/Boots/Boots_9.png");
    images["Boots5"] = LoadGraph("data/image/Icons/Boots/Boots_10.png");

    //BackGround
    images["performance"] = LoadGraph("data/image/Art/performance.png");
    images["equipment1"] = LoadGraph("data/image/Art/equipment1.png");
    images["equipment2"] = LoadGraph("data/image/Art/equipment2.png");
    images["equipment3"] = LoadGraph("data/image/Art/equipment3.png");
    images["equipment4"] = LoadGraph("data/image/Art/equipment4.png");


    images["+1"] = LoadGraph("data/image/Art/+1.png");// next
    images["-1"] = LoadGraph("data/image/Art/-1.png");// back


    //ListScene
    images["listBg"] = LoadGraph("data/image/Art/ListScene.png");
}

int ImageManager::Get(const std::string& name)
{
    return images[name];
}
