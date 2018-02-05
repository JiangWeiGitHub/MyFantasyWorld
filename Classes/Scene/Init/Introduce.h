#ifndef __INTRODUCESCENE_H__
#define __INTRODUCESCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class IntroduceScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getIntroduceScene();
    virtual bool init();

    CREATE_FUNC(IntroduceScene);
  };

}

#endif // __INTRODUCESCENE_H__