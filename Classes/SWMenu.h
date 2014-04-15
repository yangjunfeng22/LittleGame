//
//  SWMenu.h
//  HelloCpp
//
//  Created by yang on 14-4-15.
//
//

#ifndef __HelloCpp__SWMenu__
#define __HelloCpp__SWMenu__

#include <iostream>
#include "cocos2d.h"

class SWMenu : public cocos2d::Layer {
    
public:
    virtual bool init();
    static cocos2d::Scene *scene();
    CREATE_FUNC(SWMenu);
    
private:
    // 设置按钮的点击事件, 点击开始游戏
    // 点击设置
    void SecttingPressed(Object* pSender);
    // 点击开始游戏
    void PlayPressed(Object* pSender);
    // 点击人物设置
    void MyHoldTailPressed(Object* pSender);
    // 点击帮助
    void HelpPressed(Object* pSender);
};

#endif /* defined(__HelloCpp__SWMenu__) */
