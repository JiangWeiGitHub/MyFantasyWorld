#ifndef __HOME_H__
#define __HOME_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Layer/Main/MainLayer.h"

namespace jiangweigithub {

  class Home : public cocos2d::Scene
  {
  public:
    // Home();
    // ~Home();

    static cocos2d::Scene* getHomeScene();

    virtual bool init();

    CREATE_FUNC(Home);

    // void loadingSceneCallback(cocos2d::director* callback);

  private:
    // cocos2d::Scene* mainScene;
  };

}

#endif // __HOME_H__