#include "./System.h"

namespace jiangweigithub {

  cocos2d::Scene* SystemScene::getSystemScene()
  {
    auto tmp = SystemScene::create();

    return tmp;
  }

  bool SystemScene::init()
  {
    if(!cocos2d::Scene::create()) 
    {
      return false;
    }

    auto tmp = BackgroundLayer::getBackgroundLayer();

    // if(Director::getChapter() == CHAPTER::HOME)
    // {

    // }

    this->addChild(tmp, 0);

    return true;
  }

}