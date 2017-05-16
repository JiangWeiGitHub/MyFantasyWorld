#ifndef __TALKFRAME_H__
#define __TALKFRAME_H__

#include "iostream"
#include "cocos2d.h"

#include "../../../Sprite/Main/MainSprite.h"

namespace jiangweigithub {

  class TalkFrame : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getTalkFrame();
    virtual bool init();

    CREATE_FUNC(TalkFrame);

  private:
    // // Login callback
    // void onConfigGame(cocos2d::Ref* callback);
    // void onNewGame(cocos2d::Ref* callback);
    // void onLoadGame(cocos2d::Ref* callback);

    // void gotoHomeScene();
  };
  
}

#endif // __TALKFRAME_H__