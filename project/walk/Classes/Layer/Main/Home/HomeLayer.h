#ifndef __MAINLAYER_H__
#define __MAINLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Sprite/Main/MainSprite.h"

namespace jiangweigithub {
  
  class HomeLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getHomeLayer();
    virtual bool init();

    CREATE_FUNC(HomeLayer);
  };

}

#endif // __MAINLAYER_H__