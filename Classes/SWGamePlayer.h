//
//  SWGamePlayer.h
//  HelloCpp
//
//  Created by yang on 14-4-16.
//
//

#ifndef __HelloCpp__SWGamePlayer__
#define __HelloCpp__SWGamePlayer__

#include <iostream>
#include <sstream>
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace std;
using namespace extension;

// 类型转换int.float --> string
template <typename T>
string Convert2String(const T & value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

// 定义图片的枚举类型
typedef enum{
    tag_player_up,
    tag_player_down,
    tag_player_fly,
    tag_player_run,
    tag_player_Hp,
}tagPlayers;

class SWGamePlayer:public cocos2d::Sprite {
    
public:
    static SWGamePlayer *createPlayer(const char *fileName, int allCount, float sprit);
    
    // 降低主角的血量
    void downHp(float _value);
    int hp;//血量
    int hpMax;//最高血量
    static SWGamePlayer *sharedPlayer();
    
    void callbackForDown();
private:
    void playerInit(const char *fileName, int allCount, float sprit);
    // 精灵的动态表现 文件名称 文件帧数 精灵速度
    void createAnimate(const char *fileName, int allCount, float sprit);
    
    
    bool isStrong;
    int strongCount;
    int strongTime;
    void strongIng(float soso);
};

#endif /* defined(__HelloCpp__SWGamePlayer__) */
