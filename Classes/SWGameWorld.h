//
//  SWGameWorld.h
//  HelloCpp
//
//  Created by yang on 14-4-15.
//
//

#ifndef __HelloCpp__SWGameWorld__
#define __HelloCpp__SWGameWorld__

#include <iostream>
#include "cocos2d.h"

// 定义属性
typedef enum{
    tag_player
}tagWorld;

class SWGameWorld:public cocos2d::Layer {
    
public:
    static cocos2d::Scene *scene();
    static SWGameWorld *sharedWorld();
    
private:
    virtual bool init();
    CREATE_FUNC(SWGameWorld);
};

#endif /* defined(__HelloCpp__SWGameWorld__) */
