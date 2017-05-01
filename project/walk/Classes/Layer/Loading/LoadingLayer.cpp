#include "./LoadingLayer.h"

namespace jiangweigithub {

  // LoadingLayer::LoadingLayer()
  // {
  //   loadingLayer = NULL;

  //   loadingSprite = NULL;
  //   loadingTitle = NULL;
  // }

  // LoadingLayer::~LoadingLayer()
  // {
  //   delete loadingTitle;
  //   delete loadingSprite;
  //   delete loadingLayer;
  // }

  bool LoadingLayer::init()
  {
    if ( !Layer::init() )
    {
      return false;
    }

    auto loadingSprite = LoadingSprite::getLoadingSprite();
    auto loadingTitle = LoadingTitleSprite::getLoadingTitle();

    auto spriteSize = loadingSprite->getContentSize();
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    loadingSprite->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2));
    loadingTitle->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2 + 60));

    this->addChild(loadingSprite);
    this->addChild(loadingTitle);

    return true;
  }

  cocos2d::Layer* LoadingLayer::getLoadingLayer()
  {
    // loadingLayer = cocos2d::Layer::create();

    // loadingSprite = (new LoadingSprite())->getLoadingSprite();
    // loadingTitle = (new LoadingSprite())->getLoadingTitle();

    // auto spriteSize = loadingSprite->getContentSize();
    // auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    // loadingSprite->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2));
    // loadingTitle->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2 + 60));

    // loadingLayer->addChild(loadingSprite);
    // loadingLayer->addChild(loadingTitle);

    auto tmp = LoadingLayer::create();

    return tmp;
  }

}