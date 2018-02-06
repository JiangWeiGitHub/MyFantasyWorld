#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Director/Director.h"
#include "../../Layer/System/Background.h"

namespace jiangweigithub {

  class SystemScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getSystemScene();
    virtual bool init();

    CREATE_FUNC(SystemScene);
  };

}

#endif // __SYSTEM_H__