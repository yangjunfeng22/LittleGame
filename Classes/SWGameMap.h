//
//  SWGameMap.h
//  HelloCpp
//
//  Created by yang on 14-4-15.
//
//

#ifndef __HelloCpp__SWGameMap__
#define __HelloCpp__SWGameMap__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

// 定义图片的枚举的类型
typedef enum {
    tag_Img01_01,
    tag_Img01_02,
    tag_Img02_01,
    tag_Img02_02,
    tag_Img03_01,
    tag_Img03_02,
    tag_Img04_01,
    tag_Img04_02,
    tag_Img05_01,
    tag_Img05_02,
    tag_Img06_01,
    tag_Img06_02
}tagMap;

class SWGameMap:public cocos2d::Layer{
public:
    static SWGameMap *createMap(const char *fileName01,
                                const char *fileName02,
                                const char *fileName03,
                                const char *fileName04,
                                const char *fileName05,
                                const char *fileName06);
    // 提供一个方法修改所有图片的高度，使之随着背景移动
    static void updateLayerHeight(float layh);
    
    // 提供一个公共静态的方法获取地图对象
    static SWGameMap *sharedMap();
    // 获取地图现在的高度
    float getMapHeight();
    
    // 地图下移 每次下移的高度
    void downMap(float time);
    // 地图上移 每次上移的高度
    void upMap(float time);
    
private:
    void mapInit(const char *fileName01,
                 const char *fileName02,
                 const char *fileName03,
                 const char *fileName04,
                 const char *fileName05,
                 const char *fileName06);
    
    void update(float time);
    virtual void onExit();
    
};

#endif /* defined(__HelloCpp__SWGameMap__) */
