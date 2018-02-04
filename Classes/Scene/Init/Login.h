#ifndef __LOGINSCENE_H__
#define __LOGINSCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Layer/Init/Login.h"

namespace jiangweigithub {

  class LoginScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getLoginScene();
    virtual bool init();

    CREATE_FUNC(LoginScene);
  };

}

#endif // __LOGINSCENE_H__