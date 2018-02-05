#ifndef __LOADING_H__
#define __LOADING_H__

#pragma once

#include "iostream"
#include <unistd.h>
#include "cocos2d.h"

#include "../../Layer/Init/Loading.h"
#include "../../Scene/Init/Login.h"
#include "../../Director/Director.h"

namespace jiangweigithub {

  class LoadingScene: public cocos2d::Scene
  {
  public:
    virtual bool init();

    CREATE_FUNC(LoadingScene);

    static cocos2d::Scene* getLoadingScene();

    void menuCloseCallback(cocos2d::Ref* pSender);

    void loadingCallback(cocos2d::Ref* callback);

  private:
    void update(float delta) override;
    int updateCounter = 0;
    int _counter = 0;
  };
  
}

#endif // __LOADING_H__