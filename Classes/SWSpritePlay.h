//
//  SWSpritePlay.h
//  Holdtail
//  精灵播放动画，让精灵动起来
//  Created by 帅 印 on 13-8-17.
//
//

#ifndef __Holdtail__SWSpritePlay__
#define __Holdtail__SWSpritePlay__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class SWSpritePlay:public cocos2d::CCSprite{
public:
    //实例化传入图片名称
    static SWSpritePlay *createPlay(const char *fileName,int allCount,float sprit);
    
private:
    //初始化
    void playInit(const char *fileName,int allCount,float sprit);
    //精灵的动态表现  文件名称  文件帧数  精灵速度
    void createAnimate(const char *fileName,int allCount,float sprit);
    
};
#endif /* defined(__Holdtail__SWSpritePlay__) */
