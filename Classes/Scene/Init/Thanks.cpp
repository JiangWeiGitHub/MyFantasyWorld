#include "./Thanks.h"

namespace jiangweigithub {

  cocos2d::Scene* ThanksScene::getThanksScene()
  {
    auto tmp = ThanksScene::create();

    return tmp;
  }

  bool ThanksScene::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto tmp = ThanksScene::getThanksScene();
    this->addChild(tmp);

    return true;
  }

}