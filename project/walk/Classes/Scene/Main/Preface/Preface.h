#ifndef __PREFACESCENE_H__
#define __PREFACESCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Layer/Main/Preface/Preface.h"

namespace jiangweigithub {

  class PrefaceScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getPrefaceScene();
    virtual bool init();

    CREATE_FUNC(PrefaceScene);

  private:
    cocos2d::DrawNode* drawRoundRect(int width, int height, float lineWidth, cocos2d::Color4F color, int radius, unsigned int segments);
  };

}

#endif // __PREFACESCENE_H__