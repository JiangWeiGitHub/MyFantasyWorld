#ifndef __MAINSPRITE_H__
#define __MAINSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class MainSprite
  {
  public:
    static cocos2d::Sprite* getLeaderSprite();
    static cocos2d::Label* getHomeTitle();
    static cocos2d::Rect getObstacle();
    static cocos2d::TMXTiledMap* getTileMapSprite();
  };
  
}

#endif // __MAINSPRITE_H__