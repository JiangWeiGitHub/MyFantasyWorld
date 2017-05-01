#ifndef __MAINLAYER_H__
#define __MAINLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Sprite/Main/MainSprite.h"

namespace jiangweigithub {
  
  class MainLayer : public cocos2d::Layer
  {
  public:
    // MainLayer();
    // ~MainLayer();

    static cocos2d::Layer* getMainLayer();

    virtual bool init();

    CREATE_FUNC(MainLayer);

  private:
    // cocos2d::Layer* mainLayer;
    // cocos2d::TMXTiledMap* tileMapSprite;
    // cocos2d::Label* homeTitle;
    // cocos2d::Sprite* leaderSprite;
    // cocos2d::Rect obstacle;
  };

}

#endif // __MAINLAYER_H__