//
//  SWSpriteRotate.h
//  Holdtail
//
//  Created by 帅 印 on 13-8-18.
//
//

#ifndef __Holdtail__SWSpriteRotate__
#define __Holdtail__SWSpriteRotate__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class SWSpriteRotate:public cocos2d::CCSprite{
public:
    //实例化传入图片名称
    static SWSpriteRotate *createPlay(const char *fileName,int sprit,int jiaodu);
    
private:
    //初始化
    void playInit(const char *fileName,int sprit,int jiaodu);
    //精灵的动态表现  文件名称  文件帧数  精灵速度
    void createAnimate(const char *fileName,int sprit,int jiaodu);
    
};
#endif /* defined(__Holdtail__SWSpriteRotate__) */
