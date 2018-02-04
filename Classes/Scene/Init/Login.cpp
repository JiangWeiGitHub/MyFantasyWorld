#include "./Login.h"

namespace jiangweigithub {

  cocos2d::Scene* LoginScene::getLoginScene()
  {
    auto tmp = LoginScene::create();

    return tmp;
  }

  bool LoginScene::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto tmp = LoginLayer::getLoginLayer();
    this->addChild(tmp);

    return true;
  }

}