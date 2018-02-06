#include "./Background.h"

namespace jiangweigithub {

  cocos2d::Layer* BackgroundLayer::getBackgroundLayer()
  {
    auto tmp = BackgroundLayer::create();

    return tmp;
  }

  bool BackgroundLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto backPic = cocos2d::Sprite::create("config_background.jpg");
    backPic->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(backPic, 0);

    auto title = cocos2d::Label::createWithTTF("Configuration", "fonts/MSYHBD.TTF", 28);
    title->setTextColor(cocos2d::Color4B(255,255,255,200));
    title->enableShadow();
    title->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 300));
    this->addChild(title, 1);

    // this->scheduleUpdate();

    return true;  
  }


  void BackgroundLayer::update(float delta)
  {

  }

  // void BackgroundLayer::_gotoHomeScene()
  // {
  //   auto homeScene = jiangweigithub::HomeScene::getHomeScene();
  //   cocos2d::Director::getInstance()->replaceScene(homeScene);
  // }

}