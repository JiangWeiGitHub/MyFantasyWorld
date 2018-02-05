#ifndef __THANKSSCENE_H__
#define __THANKSSCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "./Loading.h"
#include "./Login.h"

namespace jiangweigithub {

  class ThanksScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getThanksScene();
    virtual bool init();

  private:
    void update(float delta) override;
    int counter = 0;

    CREATE_FUNC(ThanksScene);
  };

}

#endif // __THANKSSCENE_H__