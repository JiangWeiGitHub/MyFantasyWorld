#ifndef __LOADING_H__
#define __LOADING_H__

#pragma once

#include "iostream"
#include <unistd.h>
#include "cocos2d.h"

#include "../../Layer/Loading/LoadingLayer.h"
#include "../../Scene/Main/Login/Login.h"

namespace jiangweigithub {

  class LoadingScene: public cocos2d::Scene
  {
  public:
    // LoadingScene();
    // ~LoadingScene();

    virtual bool init();

    CREATE_FUNC(LoadingScene);

    static cocos2d::Scene* getLoadingScene();
    // void loadingSceneCallback();

    void menuCloseCallback(cocos2d::Ref* pSender);

    void loadingCallback(cocos2d::Ref* callback);
    void gotoLoginScene();

  private:
    int flag = 0;
  };
  
}

#endif // __LOADING_H__