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
    static cocos2d::Rect getObstacle();
    static cocos2d::TMXTiledMap* getTileMapSprite();

    // Login
    static cocos2d::Sprite* getBackgroundSprite();
    static cocos2d::MenuItemLabel* getNewGame();
    static cocos2d::MenuItemLabel* getLoadGame();
    static cocos2d::MenuItemLabel* getConfigGame();

  };
  
}

#endif // __MAINSPRITE_H__