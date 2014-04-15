//
//  SWMenu.cpp
//  HelloCpp
//
//  Created by yang on 14-4-15.
//
//

#include "SWMenu.h"
#include "SWSpritePlay.h"
#include "SWSpriteRotate.h"
#include "SWGameWorld.h"

using namespace cocos2d;

Scene *SWMenu::scene(){
    auto scene = Scene::create();
    auto layer = SWMenu::create();
    
    scene->addChild(layer);
    return scene;
}

// 初始化的方法
bool SWMenu::init(){
    if (!Layer::init()) {
        return false;
    }
    
    // 获取屏幕大小
    Size size = Director::getInstance()->getWinSize();
    
    // 创建Menu背景
    auto sp = LayerColor::create(Color4B(0, 255, 0, 255));
    addChild(sp);
    
    Sprite *sptop = Sprite::create("holdtailtitletxt.png");
    sptop->setPosition(Point(size.width*0.5-30, size.height-100));
    sptop->setZOrder(1);
    addChild(sptop);
    
    Sprite *spbutton = Sprite::create("copyright.png");
    spbutton->setPosition(Point(size.width*0.5, 10));
    spbutton->setZOrder(1);
    addChild(spbutton);
    
    // 创建菜单
    auto itemPlay = MenuItemImage::create("play.png", "playon.png", CC_CALLBACK_1(SWMenu::PlayPressed, this));
    itemPlay->setPosition(Point(-67, -200));
    
    auto itemSetting = MenuItemImage::create("setting.png", "setting.png", CC_CALLBACK_1(SWMenu::SecttingPressed, this));
    itemSetting->setPosition(Point(-400, -250));
    
    auto itemMyHold = MenuItemImage::create("myhot.png", "myhoton.png",CC_CALLBACK_1(SWMenu::MyHoldTailPressed, this));
    itemMyHold->setPosition(Point(67, -200));
    
    auto itemHelp = MenuItemImage::create("help.png", "help.png",CC_CALLBACK_1(SWMenu::HelpPressed, this));
    itemHelp->setPosition(Point(400, -250));
    
    Menu *menu = Menu::create(itemPlay, itemSetting, itemMyHold, itemHelp, NULL);
    menu->setZOrder(3);
    addChild(menu);
    
    // 加入人物
    auto SSP_Tail = SWSpritePlay::createPlay("interviewtail.png", 8, 0.15f);
    SSP_Tail->setPosition(Point(size.width*0.5+200, size.height*0.5-50));
    SSP_Tail->setZOrder(1);
    addChild(SSP_Tail);
    
    // 加入尾巴
    SWSpritePlay *SSP_Weiba = SWSpritePlay::createPlay("tail.png", 4, 0.3f);
    SSP_Weiba->setPosition(Point(size.width*0.5+270, size.height-102));
    SSP_Weiba->setZOrder(1);
    addChild(SSP_Weiba);
    
    // 加入旋转
    SWSpriteRotate *SSP_bg = SWSpriteRotate::createPlay("ballbg.png", 60, 360);
    SSP_bg->setPosition(Point(size.width*0.5, size.height*0.5-920));
    SSP_bg->setZOrder(0);
    addChild(SSP_bg);
    
    return true;
}

void SWMenu::PlayPressed(Object *pSender){
    CCDirector::getInstance()->replaceScene(CCTransitionFade::create(0.5, SWGameWorld::scene()));
}

void SWMenu::SecttingPressed(Object *pSender){
    
}

void SWMenu::MyHoldTailPressed(Object *pSender){
    
}

void SWMenu::HelpPressed(Object *pSender){
    
}
