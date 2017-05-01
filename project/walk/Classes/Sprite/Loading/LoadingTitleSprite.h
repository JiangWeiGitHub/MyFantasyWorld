#ifndef __LOADINGTITLESPRITE_H__
#define __LOADINGTITLESPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class LoadingTitleSprite: public cocos2d::Label
  {
  public:
    // LoadingTitleSprite();
    // ~LoadingTitleSprite();

    virtual bool init();

    // static cocos2d::Sprite* getLoadingSprite();
    static cocos2d::Label* getLoadingTitle();

    CREATE_FUNC(LoadingTitleSprite);

  private:
    // bool createLoadingSprite();
    bool createTitle(std::string name);

    // static cocos2d::Sprite* loadingSprite;
    // static cocos2d::Label* loadingTitle;
  };
  
}
#endif // __LOADINGTITLESPRITE_H__