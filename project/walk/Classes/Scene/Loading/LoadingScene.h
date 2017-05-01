#ifndef __LOADING_H__
#define __LOADING_H__

#pragma once

#include "iostream"
#include <unistd.h>
#include "cocos2d.h"

#include "../../Layer/Loading/LoadingLayer.h"
#include "../../Scene/Main/Home/Home.h"

namespace jiangweigithub {

  class LoadingScene: public cocos2d::Scene
  {
  public:
    // LoadingScene();
    // ~LoadingScene();

    virtual bool init();

    CREATE_FUNC(LoadingScene);

    void myThreadA();

    static cocos2d::Scene* getLoadingScene();
    static void loadingSceneCallback(cocos2d::Ref* pSender);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

  private:
    // static cocos2d::Scene* loadingScene;
  };
  
}

#endif // __LOADING_H__