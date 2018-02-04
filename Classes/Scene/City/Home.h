#ifndef __HOMESCENE_H__
#define __HOMESCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Director/Director.h"
#include "../../Layer/City/Home.h"
#include "../../Layer/Talk/TalkFrame.h"

namespace jiangweigithub {

  class HomeScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getHomeScene();
    virtual bool init();

    CREATE_FUNC(HomeScene);
  };

}

#endif // __HOMESCENE_H__