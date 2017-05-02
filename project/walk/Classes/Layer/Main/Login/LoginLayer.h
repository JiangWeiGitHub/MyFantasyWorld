#ifndef __LOGINLAYER_H__
#define __LOGINLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Sprite/Main/MainSprite.h"

namespace jiangweigithub {
  
  class LoginLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getLoginLayer();
    virtual bool init();

    CREATE_FUNC(LoginLayer);
  };

}

#endif // __LOGINLAYER_H__