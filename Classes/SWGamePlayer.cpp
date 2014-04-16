//
//  SWGamePlayer.cpp
//  HelloCpp
//
//  Created by yang on 14-4-16.
//
//

#include "SWGamePlayer.h"
#include "SWGameMap.h"
#include "SWGameWorld.h"
#include "SimpleAudioEngine.h"
#include "SWMenu.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace CocosDenshion;

// 设置主角精灵的两种表现形式
static Sprite *flySprite;
static Sprite *runSprite;

// 声明静态变量
static SWGamePlayer *SWPL;

SWGamePlayer *SWGamePlayer::sharedPlayer(){
    if (SWPL != NULL) {
        return SWPL;
    }
    return NULL;
}

SWGamePlayer *SWGamePlayer::createPlayer(const char *fileName, int allCount, float sprit){
    SWGamePlayer *player = new SWGamePlayer();
    
    if (player && player->initWithFile("nulls.png")) {
        player->autorelease();
        player->playerInit(fileName, allCount, sprit);
        return player;
    }
    
    CC_SAFE_DELETE(player);
    return NULL;
}

void SWGamePlayer::playerInit(const char *fileName, int allCount, float sprit){
    SWPL = this;
    
    Size size = Director::getInstance()->getWinSize();
    
    // 主角加入枪支
    auto spgane = Sprite::create("gang01.png");
    spgane->setPosition(Point(40, -10));
    addChild(spgane);
    
    // 创建动物的动画
    createAnimate(fileName, allCount, sprit);
    
    // 初始化主角的位置
    this->setPosition(Point(size.width/8, size.height/2));
    
    // 设置血量
    hp = 1000;
    hpMax = 1000;
    
    ControlSlider *slider = ControlSlider::create("brood.png", "broods.png", "null.png");
    slider->setPosition(Point(250, size.height-40));
    slider->setTag(tag_player_Hp);
    
    /*设置滑动条的范围*/
    slider->setMinimumValue(0);
    slider->setMaximumValue(hpMax);
    /*直接设置滑动条的当前值*/
    slider->setValue(hp);
    
    SWGameWorld::sharedWorld()->addChild(slider);
    
    // 添加主角形象
    Sprite *hmsprite = Sprite::create("gameicon.png");
    hmsprite->setPosition(Point(50, size.height-40));
    SWGameWorld::sharedWorld()->addChild(hmsprite);
    
    // 添加游戏进行进度条
    Sprite *timebg = Sprite::create("timelinebg.png");
    timebg->setPosition(Point(670, size.height-35));
    SWGameWorld::sharedWorld()->addChild(timebg);
    
    // 添加游戏进行条动画效果
    Sprite *timeplay = Sprite::create("timelineyou.png");
    timeplay->setPosition(Point(510, size.height-40));
    SWGameWorld::sharedWorld()->addChild(timeplay);
    
    //让动画进行播放
    //    ActionInterval* moveToGameOver = MoveBy::create(120, Point(320, 0));
    //    CallFunc * funCall =CallFunc::create(timeplay, callfunc_selector(SWGamePlayer::gameGoOver));
    //    FiniteTimeAction *seq =Sequence::create(moveToGameOver,funCall,NULL);
    //    seq->setTag(tag_player_down);
    //    timeplay->runAction(seq);
    
    //    MenuItemImage *SPJN01ITEM = MenuItemImage::create("pausebutton.png", "pausedownbutton.png",this,menu_selector(SWGamePlayer::backMenu));
    //    SPJN01ITEM->setPosition(Point(420,280));
    //    Menu *menu = Menu::create(SPJN01ITEM,NULL);
    //    SWGameWorld::sharedWorld()->addChild(menu);
}

void SWGamePlayer::createAnimate(const char *fileName, int allCount, float sprit)
{
    runSprite = Sprite::create("zhujuerun.png");
    runSprite->setTag(tag_player_run);
    Animation *animation = Animation::create();
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("zhujuerun.png");
    int eachWidth = runSprite->getContentSize().width/8;
    for (int i = 0; i < 8; i++)
    {
        animation->addSpriteFrameWithTexture(texture, Rect(i*eachWidth, 0, eachWidth, this->getContentSize().height));
        
    }
    animation->setDelayPerUnit(0.1f);//必须设置否则不会动态播放
    animation->setRestoreOriginalFrame(true);//是否回到第一个
    animation->setLoops(-1);//重复次数
    FiniteTimeAction *animatierun = Animate::create(animation);
    runSprite->setPosition(this->getPosition());
    runSprite->runAction(animatierun);
    this->addChild(runSprite);
    
    flySprite = Sprite::create("zhujue.png");
    flySprite->setTag(tag_player_fly);
    Animation *animations = Animation::create();
    Texture2D *textures = Director::getInstance()->getTextureCache()->addImage("zhujue.png");
    int eachWidths = flySprite->getContentSize().width/8;
    for (int i = 0; i < 8; i++)
    {
        animations->addSpriteFrameWithTexture(textures, Rect(i*eachWidths, 0, eachWidths, this->getContentSize().height));
    }
    animations->setDelayPerUnit(0.05f);//必须设置否则不会动态播放
    animations->setRestoreOriginalFrame(true);//是否回到第一个
    animations->setLoops(-1);//重复次数
    FiniteTimeAction *animateruns = Animate::create(animations);
    flySprite->setPosition(this->getPosition());
    flySprite->runAction(animateruns);
    this->addChild(flySprite);
    
    runSprite->setOpacity(0);
    flySprite->setOpacity(255);
}
