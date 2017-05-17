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
    void _NextPageCallback(cocos2d::Ref* pSender);
  };
  
}

#endif // __TALKFRAME_H__