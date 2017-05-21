#include "./Preface.h"

namespace jiangweigithub {

  cocos2d::Scene* PrefaceScene::getPrefaceScene()
  {
    auto tmp = PrefaceScene::create();

    return tmp;
  }

  bool PrefaceScene::init()
  {
    if(!cocos2d::Scene::init()) 
    {
      return false;
    }

    auto tmp = PrefaceLayer::getPrefaceLayer();
    this->addChild(tmp, 0);

    return true;
  }

}