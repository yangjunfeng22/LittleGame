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
    Animation *animation = Animation::create();
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(fileName);
    int eachWidth = this->getContentSize().width/allCount;
    for (int i = 0; i<allCount; i++) {
        animation->addSpriteFrameWithTexture(texture, Rect(i*eachWidth, 0, eachWidth, this->getContentSize().height));
    }
    animation->setDelayPerUnit(sprit);//必须设置否则不会动态播放
    animation->setRestoreOriginalFrame(true);//是否回到第一个
    animation->setLoops(-1);//重复次数
    FiniteTimeAction *animate = Animate::create(animation);
    this->runAction(animate);
}