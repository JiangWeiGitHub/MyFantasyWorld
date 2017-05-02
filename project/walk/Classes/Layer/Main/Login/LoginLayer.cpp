#include "./LoginLayer.h"

namespace jiangweigithub {

  cocos2d::Layer* LoginLayer::getLoginLayer()
  {
    auto tmp = LoginLayer::create();

    return tmp;
  }

  bool LoginLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    auto background = MainSprite::getBackgroundSprite();
    auto loginMenu = (new MainSprite())->getLoginMenu();

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    auto loginMenuSize = loginMenu->getContentSize();

    background->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    loginMenu->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));

    this->addChild(background, -1);
    this->addChild(loginMenu, 0);

    return true;
  }

}