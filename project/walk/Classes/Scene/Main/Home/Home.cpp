#include "./Home.h"

namespace jiangweigithub {

  // Home::Home()
  // {
  //   mainScene = cocos2d::Scene::create();
  // }
  
  // Home::~Home()
  // {
  //   delete mainScene;
  // }  

  cocos2d::Scene* Home::getHomeScene()
  {
    // mainScene->addChild((new MainLayer())->getMainLayer());
    // return mainScene;
    auto tmp = Home::create();

    return tmp;
  }

  bool Home::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto tmp = MainLayer::getMainLayer();
    this->addChild(tmp);

    return true;
  }

  // void Home::loadingSceneCallback(cocos2d::director* callback)
  // {
  //   sleep(5);
  //   callback();
  // }

}