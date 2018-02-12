#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#pragma once

#include "../../Global/Global.h"
#include "../../Director/Director.h"
#include "../../Processor/JsonCpp/json/json.h"
#include "../../Material/Role/Role.h"
#include "../../Material/Loading.h"
#include "../../Material/Role/Human/Protagonist.h"

namespace jiangweigithub {

  class LoadingLayer : public cocos2d::Layer
  {
  public:
    virtual bool init();

    static cocos2d::Layer* getLoadingLayer();

    CREATE_FUNC(LoadingLayer);
  };

}

#endif // __LOADINGLAYER_H__