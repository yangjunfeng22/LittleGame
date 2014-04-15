//
//  SWGameWorld.cpp
//  HelloCpp
//
//  Created by yang on 14-4-15.
//
//

#include "SWGameWorld.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SWGameMap.h"

using namespace cocos2d;
using namespace CocosDenshion;

// 声名静态变量
static SWGameWorld *SWGW;

SWGameWorld *SWGameWorld::sharedWorld(){
    if (SWGW != NULL) {
        return SWGW;
    }
    return NULL;
}

Scene *SWGameWorld::scene(){
    Scene *scene = Scene::create();
    SWGameWorld *layer = SWGameWorld::create();
    scene->addChild(layer);
    return scene;
}

//创建场景
bool SWGameWorld::init(){
    if( !Layer::init()){
        return false;
    }
    SWGW = this;
    
    //地图
    SWGameMap *map = SWGameMap::createMap("cloudbg.png","cloud04.png","cloud03.png","cloud02.png","cloud01.png","treesbg.png");
    
    addChild(map);
    
    return true;
}