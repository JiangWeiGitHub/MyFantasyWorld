#ifndef __MAINSPRITE_H__
#define __MAINSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class MainSprite
  {
  public:
    // MainSprite();
    // ~MainSprite();

    static cocos2d::Sprite* getLeaderSprite();
    static cocos2d::Label* getHomeTitle();
    static cocos2d::Rect getObstacle();
    static cocos2d::TMXTiledMap* getTileMapSprite();

  private:
    bool createLeaderSprite();
    bool createMapSprite();
    bool createObstacle();
    bool createTitle(std::string name);

    cocos2d::TMXTiledMap* tileMapSprite;
    cocos2d::Label* homeTitle;
    cocos2d::Sprite* leaderSprite;
    cocos2d::Rect obstacle;
  };
  
}

#endif // __MAINSPRITE_H__