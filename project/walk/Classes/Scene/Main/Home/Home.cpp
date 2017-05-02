#include "./Home.h"

namespace jiangweigithub {

  cocos2d::Scene* Home::getHomeScene()
  {
    auto tmp = Home::create();

    return tmp;
  }

  bool Home::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto tmp = HomeLayer::getHomeLayer();
    this->addChild(tmp);

    return true;
  }

}