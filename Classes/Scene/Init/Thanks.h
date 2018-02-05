#ifndef __THANKSSCENE_H__
#define __THANKSSCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class ThanksScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getThanksScene();
    virtual bool init();

    CREATE_FUNC(ThanksScene);
  };

}

#endif // __THANKSSCENE_H__