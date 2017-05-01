#ifndef __LOADINGSPRITE_H__
#define __LOADINGSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class LoadingSprite: public cocos2d::Sprite
  {
  public:
    virtual bool init();

    static cocos2d::Sprite* getLoadingSprite();
    // static cocos2d::Label* getLoadingTitle();

    CREATE_FUNC(LoadingSprite);

  private:
    cocos2d::Sprite* createLoadingSprite();
    // bool createTitle(std::string name);

    // static cocos2d::Sprite* loadingSprite;
    // static cocos2d::Label* loadingTitle;
  };
  
}
#endif // __LOADINGSPRITE_H__