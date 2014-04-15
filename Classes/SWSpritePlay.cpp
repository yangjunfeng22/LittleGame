//
//  SWSpritePlay.cpp
//  Holdtail
//  
//  Created by 帅 印 on 13-8-17.
//
//

#include "SWSpritePlay.h"
#include "cocos2d.h"

using namespace cocos2d;

SWSpritePlay *SWSpritePlay::createPlay(const char *fileName,int allCount,float sprit){
    SWSpritePlay *spritePlay = new SWSpritePlay();
    if(spritePlay && spritePlay->initWithFile(fileName)){
        spritePlay->autorelease();
        spritePlay->playInit(fileName,allCount,sprit);
        return spritePlay;
    }
    return NULL;
}

//初始化
void SWSpritePlay::playInit(const char *fileName,int allCount,float sprit){
    //创建动物的动画
    createAnimate(fileName,allCount,sprit);
}

void SWSpritePlay::createAnimate(const char *fileName,int allCount,float sprit){
    CCAnimation *animation = CCAnimation::create();
    CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(fileName);
    int eachWidth = this->getContentSize().width/allCount;
    for (int i = 0; i<allCount; i++) {
        animation->addSpriteFrameWithTexture(texture, CCRectMake(i*eachWidth, 0, eachWidth, this->getContentSize().height));
    }
    animation->setDelayPerUnit(sprit);//必须设置否则不会动态播放
    animation->setRestoreOriginalFrame(true);//是否回到第一个
    animation->setLoops(-1);//重复次数
    CCFiniteTimeAction *animate = CCAnimate::create(animation);
    this->runAction(animate);
}