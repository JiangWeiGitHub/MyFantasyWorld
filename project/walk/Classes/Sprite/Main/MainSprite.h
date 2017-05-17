#ifndef __MAINSPRITE_H__
#define __MAINSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Scene/Main/Home/Home.h"

namespace jiangweigithub {

  class MainSprite
  {
  public:
    // Home
    static cocos2d::Sprite* getLeaderSprite();
    static cocos2d::Label* getHomeTitle();
    static cocos2d::TMXTiledMap* getTileMapSprite();

    // Login
    static cocos2d::Sprite* getBackgroundSprite();
    static cocos2d::MenuItemLabel* getNewGame();
    static cocos2d::MenuItemLabel* getLoadGame();
    static cocos2d::MenuItemLabel* getConfigGame();

    // Dialog box
    static cocos2d::DrawNode* getDrawFrame();
    static cocos2d::Sprite* getFrameLeftFlowers();
    static cocos2d::Sprite* getFrameRightFlowers();

    static cocos2d::Sprite* getAvatar();
    static cocos2d::Label* getFirstLine();
    static void setFirstLine(std::string contents);
    static cocos2d::Label* getSecondLine();
    static void setSecondLine(std::string contents);
    static cocos2d::Label* getThirdLine();
    static void setThirdLine(std::string contents);
    static cocos2d::Label* getPeopleName();
    static void setPeopleName(std::string contents);
    static cocos2d::MenuItemImage* getNextPageItem();
    static cocos2d::Menu* getNextPage();

    static cocos2d::Label* _firstLine;
    static cocos2d::Label* _secondLine;
    static cocos2d::Label* _thirdLine;
    static cocos2d::Label* _peopleName;

    static cocos2d::MenuItemImage* nextPageItem;
  };
  
}

#endif // __MAINSPRITE_H__