//
//  SWGameMap.cpp
//  HelloCpp
//
//  Created by yang on 14-4-15.
//
//

#include "SWGameMap.h"
#include "SWGameWorld.h"

static float layHeight;
static SWGameMap *sm;

SWGameMap *SWGameMap::sharedMap(){
    if (sm != NULL) {
        return sm;
    }
    return NULL;
}

// 创建一个地图对象
SWGameMap *SWGameMap::createMap(const char *fileName01, const char *fileName02, const char *fileName03, const char *fileName04, const char *fileName05, const char *fileName06)
{
    SWGameMap *map = new SWGameMap();
    if (map && map->create()) {
        layHeight = 210;
        
        map->autorelease();
        map->mapInit(fileName01, fileName02, fileName03, fileName04, fileName05, fileName06);
        
        return map;
    }
    CC_SAFE_DELETE(map);
    return NULL;
}

float SWGameMap::getMapHeight(){
    return layHeight;
}

// 提供一个方法修改所有图片的高度, 使之随着背景移动
void SWGameMap::updateLayerHeight(float layh){
    if (0 == layh) {
        // 地图的上下移动
        sm->unschedule(schedule_selector(SWGameMap::upMap));
        sm->schedule(schedule_selector(SWGameMap::downMap), 0.005f);
    }else if (1 == layh){
        // 地图的上下移动
        sm->unschedule(schedule_selector(SWGameMap::downMap));
        sm->schedule(schedule_selector(SWGameMap::upMap), 0.005f);
    }
}

void SWGameMap::downMap(float time){
    float layh = -2;
    // 控制地图的最低高度
    if (layHeight >= -500) {
        layHeight = layHeight+layh;
        
        Sprite *sp0201 = (Sprite *)sm->getChildByTag(tag_Img02_01);
        sp0201->setPosition(sp0201->getPosition() + Point(0, layh));
        
        Sprite *sp0202 = (Sprite *)sm->getChildByTag(tag_Img02_02);
        sp0202->setPosition(sp0202->getPosition() + Point(0, layh));
        
        Sprite *sp0301 = (Sprite *)sm->getChildByTag(tag_Img03_01);
        sp0301->setPosition(sp0301->getPosition() + Point(0, layh));
        Sprite *sp0302 = (Sprite *)sm->getChildByTag(tag_Img03_02);
        sp0302->setPosition(sp0302->getPosition() + Point(0, layh));
        
        Sprite *sp0401 = (Sprite *)sm->getChildByTag(tag_Img04_01);
        sp0401->setPosition(sp0401->getPosition() + Point(0, layh));
        Sprite *sp0402 = (Sprite *)sm->getChildByTag(tag_Img04_02);
        sp0402->setPosition(sp0402->getPosition() + Point(0, layh));
        
        Sprite *sp0501 = (Sprite *)sm->getChildByTag(tag_Img05_01);
        sp0501->setPosition(sp0501->getPosition() + Point(0, layh));
        Sprite *sp0502 = (Sprite *)sm->getChildByTag(tag_Img05_02);
        sp0502->setPosition(sp0502->getPosition() + Point(0, layh));
        
        Sprite *sp0601 = (Sprite *)sm->getChildByTag(tag_Img06_01);
        sp0601->setPosition(sp0601->getPosition() + Point(0, layh));
        Sprite *sp0602 = (Sprite *)sm->getChildByTag(tag_Img06_02);
        sp0602->setPosition(sp0602->getPosition() + Point(0, layh));
    }else{
        // 自动停止
        sm->unschedule(schedule_selector(SWGameMap::downMap));
    }
}

void SWGameMap::upMap(float time){
    float layh = +2;
    //控制人物的最高高度
    if (layHeight < 210) {
        
        layHeight = layHeight+layh;
        /*
        Sprite *sp0101 = (Sprite *)sm->getChildByTag(tag_Img01_01);
        sp0101->setPosition(sp0101->getPosition() + Point(0, layh));
        Sprite *sp0102 = (Sprite *)sm->getChildByTag(tag_Img01_02);
        sp0102->setPosition(sp0102->getPosition()+ Point(0, layh));
        */
        Sprite *sp0201 = (Sprite *)sm->getChildByTag(tag_Img02_01);
        sp0201->setPosition(sp0201->getPosition() + Point(0, layh));
        Sprite *sp0202 = (Sprite *)sm->getChildByTag(tag_Img02_02);
        sp0202->setPosition(sp0202->getPosition() + Point(0, layh));
        
        Sprite *sp0301 = (Sprite *)sm->getChildByTag(tag_Img03_01);
        sp0301->setPosition(sp0301->getPosition() + Point(0, layh));
        Sprite *sp0302 = (Sprite *)sm->getChildByTag(tag_Img03_02);
        sp0302->setPosition(sp0302->getPosition() + Point(0, layh));
        
        Sprite *sp0401 = (Sprite *)sm->getChildByTag(tag_Img04_01);
        sp0401->setPosition(sp0401->getPosition() + Point(0, layh));
        Sprite *sp0402 = (Sprite *)sm->getChildByTag(tag_Img04_02);
        sp0402->setPosition(sp0402->getPosition() + Point(0, layh));
        
        Sprite *sp0501 = (Sprite *)sm->getChildByTag(tag_Img05_01);
        sp0501->setPosition(sp0501->getPosition() + Point(0, layh));
        Sprite *sp0502 = (Sprite *)sm->getChildByTag(tag_Img05_02);
        sp0502->setPosition(sp0502->getPosition() + Point(0, layh));
        
        Sprite *sp0601 = (Sprite *)sm->getChildByTag(tag_Img06_01);
        sp0601->setPosition(sp0601->getPosition() + Point(0, layh));
        Sprite *sp0602 = (Sprite *)sm->getChildByTag(tag_Img06_02);
        sp0602->setPosition(sp0602->getPosition() + Point(0, layh));
    }else{
        //自动停止
        sm->unschedule(schedule_selector(SWGameMap::upMap));
    }
}

void SWGameMap::mapInit(const char* fileName01,
                        const char* fileName02,
                        const char* fileName03,
                        const char* fileName04,
                        const char* fileName05,
                        const char* fileName06)
{
    
    sm = this;
    
    //CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    //创建第一一个地图背景
    Sprite *turnImg0101 = Sprite::create(fileName01);
    turnImg0101->setPosition(Point(turnImg0101->getContentSize().width*0.5, 250));
    this->addChild(turnImg0101,0,tag_Img01_01);
    //创建第一二个地图背景
    Sprite *turnImg0102 = Sprite::create(fileName01);
    turnImg0102->setPosition(Point(turnImg0102->getContentSize().width*1.5, 250));
    this->addChild(turnImg0102,0,tag_Img01_02);
    
    //创建第二一个地图背景
    Sprite *turnImg0201 = Sprite::create(fileName02);
    turnImg0201->setPosition(Point(turnImg0201->getContentSize().width*0.5, layHeight+700));
    this->addChild(turnImg0201,0,tag_Img02_01);
    //创建第二二个地图背景
    Sprite *turnImg0202 = Sprite::create(fileName02);
    turnImg0202->setPosition(Point(turnImg0202->getContentSize().width*1.5, layHeight+700));
    this->addChild(turnImg0202,0,tag_Img02_02);
    
    //创建第三一个地图背景
    Sprite *turnImg0301 = Sprite::create(fileName03);
    turnImg0301->setPosition(Point(turnImg0301->getContentSize().width*0.5, layHeight+500));
    this->addChild(turnImg0301,0,tag_Img03_01);
    //创建第三二个地图背景
    Sprite *turnImg0302 = Sprite::create(fileName03);
    turnImg0302->setPosition(Point(turnImg0302->getContentSize().width*1.5, layHeight+500));
    this->addChild(turnImg0302,0,tag_Img03_02);
    
    //创建第四一个地图背景
    Sprite *turnImg0401 = Sprite::create(fileName04);
    turnImg0401->setPosition(Point(turnImg0401->getContentSize().width*0.5, layHeight+300));
    this->addChild(turnImg0401,0,tag_Img04_01);
    //创建第四二个地图背景
    Sprite *turnImg0402 = Sprite::create(fileName04);
    turnImg0402->setPosition(Point(turnImg0402->getContentSize().width*1.5, layHeight+300));
    this->addChild(turnImg0402,0,tag_Img04_02);
    
    //创建第五一个地图背景
    Sprite *turnImg0501 = Sprite::create(fileName05);
    turnImg0501->setPosition(Point(turnImg0501->getContentSize().width*0.5, layHeight+100));
    this->addChild(turnImg0501,0,tag_Img05_01);
    //创建第五二个地图背景
    Sprite *turnImg0502 = Sprite::create(fileName05);
    turnImg0502->setPosition(Point(turnImg0502->getContentSize().width*1.5, layHeight+100));
    this->addChild(turnImg0502,0,tag_Img05_02);
    
    //创建第六一个地图背景
    Sprite *turnImg0601 = Sprite::create(fileName06);
    turnImg0601->setPosition(Point(turnImg0601->getContentSize().width*0.5, layHeight));
    this->addChild(turnImg0601,0,tag_Img06_01);
    //创建第六二个地图背景
    Sprite *turnImg0602 = Sprite::create(fileName06);
    turnImg0602->setPosition(Point(turnImg0602->getContentSize().width*1.5, layHeight));
    this->addChild(turnImg0602,0,tag_Img06_02);
    
    //更新
    this->scheduleUpdate();
}

void SWGameMap::update(float time){
    //CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    //第一张图片
    Sprite *sp0101 = (Sprite *)this->getChildByTag(tag_Img01_01);
    if(sp0101->getPositionX() <= -sp0101->getContentSize().width*0.5){
        sp0101->setPosition(Point(sp0101->getContentSize().width*1.5f-2, 250));
    }else{
        sp0101->setPosition(sp0101->getPosition() + Point(-2, 0));
    }
    Sprite *sp0102 = (Sprite *)this->getChildByTag(tag_Img01_02);
    if(sp0102->getPositionX() <= -sp0102->getContentSize().width*0.5){
        sp0102->setPosition(Point(sp0102->getContentSize().width*1.5f-2, 250));
    }else{
        sp0102->setPosition(sp0102->getPosition() + Point(-2, 0));
    }
    
    //第二张图片
    Sprite *sp0201 = (Sprite *)this->getChildByTag(tag_Img02_01);
    if(sp0201->getPositionX() <= -sp0201->getContentSize().width*0.5){
        sp0201->setPosition(Point(sp0201->getContentSize().width*1.5f-3, layHeight+700));
    }else{
        sp0201->setPosition(sp0201->getPosition() + Point(-1.5, 0));
    }
    Sprite *sp0202 = (Sprite *)this->getChildByTag(tag_Img02_02);
    if(sp0202->getPositionX() <= -sp0202->getContentSize().width*0.5){
        sp0202->setPosition(Point(sp0202->getContentSize().width*1.5f-3, layHeight+700));
    }else{
        sp0202->setPosition(sp0202->getPosition() + Point(-1.5, 0));
    }
    
    //第三张图片
    Sprite *sp0301 = (Sprite *)this->getChildByTag(tag_Img03_01);
    if(sp0301->getPositionX() <= -sp0301->getContentSize().width*0.5){
        sp0301->setPosition(Point(sp0301->getContentSize().width*1.5f-2, layHeight+500));
    }else{
        sp0301->setPosition(sp0301->getPosition() + Point(-2, 0));
    }
    Sprite *sp0302 = (Sprite *)this->getChildByTag(tag_Img03_02);
    if(sp0302->getPositionX() <= -sp0302->getContentSize().width*0.5){
        sp0302->setPosition(Point(sp0302->getContentSize().width*1.5f-2, layHeight+500));
    }else{
        sp0302->setPosition(sp0302->getPosition() + Point(-2, 0));
    }
    
    //第四张图片
    Sprite *sp0401 = (Sprite *)this->getChildByTag(tag_Img04_01);
    if(sp0401->getPositionX() <= -sp0401->getContentSize().width*0.5){
        sp0401->setPosition(Point(sp0401->getContentSize().width*1.5f-2.5, layHeight+300));
    }else{
        sp0401->setPosition(sp0401->getPosition() + Point(-2.5, 0));
    }
    Sprite *sp0402 = (Sprite *)this->getChildByTag(tag_Img04_02);
    if(sp0402->getPositionX() <= -sp0402->getContentSize().width*0.5){
        sp0402->setPosition(Point(sp0402->getContentSize().width*1.5f-2.5, layHeight+300));
    }else{
        sp0402->setPosition(sp0402->getPosition() + Point(-2.5, 0));
    }
    
    //第五张图片
    Sprite *sp0501 = (Sprite *)this->getChildByTag(tag_Img05_01);
    if(sp0501->getPositionX() <= -sp0501->getContentSize().width*0.5){
        sp0501->setPosition(Point(sp0501->getContentSize().width*1.5f-3, layHeight+100));
    }else{
        sp0501->setPosition(sp0501->getPosition() + Point(-3, 0));
    }
    Sprite *sp0502 = (Sprite *)this->getChildByTag(tag_Img05_02);
    if(sp0502->getPositionX() <= -sp0502->getContentSize().width*0.5){
        sp0502->setPosition(Point(sp0502->getContentSize().width*1.5f-3, layHeight+100));
    }else{
        sp0502->setPosition(sp0502->getPosition() + Point(-3, 0));
    }
    
    //第六张图片
    Sprite *sp0601 = (Sprite *)this->getChildByTag(tag_Img06_01);
    if(sp0601->getPositionX() <= -sp0601->getContentSize().width*0.5){
        sp0601->setPosition(Point(sp0601->getContentSize().width*1.5f-4, layHeight));
    }else{
        sp0601->setPosition(sp0601->getPosition() + Point(-4, 0));
    }
    Sprite *sp0602 = (Sprite *)this->getChildByTag(tag_Img06_02);
    if(sp0602->getPositionX() <= -sp0602->getContentSize().width*0.5){
        sp0602->setPosition(Point(sp0602->getContentSize().width*1.5f-4, layHeight));
    }else{
        sp0602->setPosition(sp0602->getPosition() + Point(-4, 0));
    }
}

//退出
void SWGameMap::onExit(){
    this->unscheduleUpdate();
    CCLayer::onExit();
}
