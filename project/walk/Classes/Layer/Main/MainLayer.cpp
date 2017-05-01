#include "./MainLayer.h"

namespace jiangweigithub {

  // MainLayer::MainLayer()
  // {
  //   mainLayer = NULL;
  //   tileMapSprite = NULL;
  //   homeTitle = NULL;
  //   leaderSprite = NULL;
  //   obstacle = cocos2d::Rect(0, 0, 0, 0);
  // }

  // MainLayer::~MainLayer()
  // {
  //   obstacle = cocos2d::Rect(0, 0, 0, 0);
  //   delete leaderSprite;
  //   delete homeTitle;
  //   delete tileMapSprite;
  //   delete mainLayer;
  // }

  cocos2d::Layer* MainLayer::getMainLayer()
  {
    // mainLayer = cocos2d::Layer::create();

    // leaderSprite = (new MainSprite())->getLeaderSprite();
    // homeTitle = (new MainSprite())->getHomeTitle();
    // tileMapSprite = (new MainSprite())->getTileMapSprite();
    // obstacle = (new MainSprite())->getObstacle();

    // auto mapSpriteSize = tileMapSprite->getContentSize();
    // auto homeTitleSpriteSize = homeTitle->getContentSize();
    // auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    // tileMapSprite->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    // homeTitle->setPosition(cocos2d::Vec2((visibleSize.width - homeTitleSpriteSize.width) / 2, 660));
    // leaderSprite->setPosition(cocos2d::Vec2(280, 350));

    // mainLayer->addChild(tileMapSprite, -1);
    // mainLayer->addChild(homeTitle, 0);
    // mainLayer->addChild(leaderSprite, 1);

    // return mainLayer;

    auto tmp = MainLayer::create();

    return tmp;
  }

  bool MainLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    auto leaderSprite = MainSprite::getLeaderSprite();
    auto homeTitle = MainSprite::getHomeTitle();
    auto tileMapSprite = MainSprite::getTileMapSprite();
    auto obstacle = MainSprite::getObstacle();

    auto mapSpriteSize = tileMapSprite->getContentSize();
    auto homeTitleSpriteSize = homeTitle->getContentSize();
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    tileMapSprite->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    homeTitle->setPosition(cocos2d::Vec2((visibleSize.width - homeTitleSpriteSize.width) / 2, 660));
    leaderSprite->setPosition(cocos2d::Vec2(280, 350));

    this->addChild(tileMapSprite, -1);
    this->addChild(homeTitle, 0);
    this->addChild(leaderSprite, 1);

    return true;
  }

}