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
    auto newGame = MainSprite::getNewGame();
    auto loadGame = MainSprite::getLoadGame();
    auto configGame = MainSprite::getConfigGame();

    newGame->setCallback(CC_CALLBACK_1(LoginLayer::onNewGame, this));
    loadGame->setCallback(CC_CALLBACK_1(LoginLayer::onLoadGame, this));
    configGame->setCallback(CC_CALLBACK_1(LoginLayer::onConfigGame, this));

    auto tmp = cocos2d::Menu::create(newGame, loadGame, configGame, NULL);
    tmp->alignItemsVerticallyWithPadding(10);

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    background->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    tmp->setPosition(cocos2d::Vec2(visibleSize.width / 2, 100));

    this->addChild(background, -1);
    this->addChild(tmp, 0);

    return true;
  }

  void LoginLayer::onConfigGame(cocos2d::Ref* callback)
  {
    this->gotoHomeScene();
  }

  void LoginLayer::onNewGame(cocos2d::Ref* callback)
  {
    this->gotoHomeScene();
  }

  void LoginLayer::onLoadGame(cocos2d::Ref* callback)
  {
    this->gotoHomeScene();
  }

  void LoginLayer::gotoHomeScene()
  {
    auto homeScene = jiangweigithub::Home::getHomeScene();
    cocos2d::Director::getInstance()->replaceScene(homeScene);
  }
  

}