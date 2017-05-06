#include "./Home.h"

namespace jiangweigithub {

  cocos2d::Scene* Home::getHomeScene()
  {
    auto tmp = Home::create();

    return tmp;
  }

  bool Home::init()
  {
    if(!cocos2d::Scene::initWithPhysics()) 
    {
      return false;
    }

    this->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);

    auto tmp = HomeLayer::getHomeLayer();
    this->addChild(tmp);

    return true;
  }

}