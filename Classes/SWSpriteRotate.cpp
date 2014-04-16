//
//  SWSpriteRotate.cpp
//  Holdtail
//
//  Created by 帅 印 on 13-8-18.
//
//

#include "SWSpriteRotate.h"
#include "cocos2d.h"

using namespace cocos2d;

SWSpriteRotate *SWSpriteRotate::createPlay(const char *fileName,int sprit,int jiaodu){
    SWSpriteRotate *spriteRotate = new SWSpriteRotate();
    if(spriteRotate && spriteRotate->initWithFile(fileName)){
        spriteRotate->autorelease();
        spriteRotate->playInit(fileName,sprit,jiaodu);
        return spriteRotate;
    }
    return NULL;
}

//初始化
void SWSpriteRotate::playInit(const char *fileName,int sprit,int jiaodu){
    //创建动物的动画
    createAnimate(fileName,sprit,jiaodu);
}

void SWSpriteRotate::createAnimate(const char *fileName,int sprit,int jiaodu){
    //创建背景旋转动画
    this->create(fileName);
    ActionInterval* rotateBy = RotateBy::create(sprit, jiaodu);
    FiniteTimeAction *seq = Sequence::create(rotateBy,NULL);
    ActionInterval* repeatForever =RepeatForever::create((ActionInterval*)seq);
    this->runAction(repeatForever);
}