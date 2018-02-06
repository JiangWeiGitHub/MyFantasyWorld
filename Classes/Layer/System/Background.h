#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Global/Global.h"

namespace jiangweigithub {
  
  class BackgroundLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getBackgroundLayer();
    virtual bool init();

    CREATE_FUNC(BackgroundLayer);

  private:
    void update(float delta) override;
    // void _gotoHomeScene();
    // void _nextPageCallback(cocos2d::Ref* pSender);

    // cocos2d::Label* _text = NULL;
    // cocos2d::Size _textSize;
    // int counter = 0;
  };

}

#endif // __BACKGROUND_H__