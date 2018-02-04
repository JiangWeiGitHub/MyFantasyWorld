#include "./Loading.h"

namespace jiangweigithub {

  bool LoadingLayer::init()
  {
    if ( !Layer::init() )
    {
      return false;
    }

    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");

    // right
    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));

    cocos2d::Vector<cocos2d::SpriteFrame*> right;
    right.pushBack(frame1);
    right.pushBack(frame2);
    right.pushBack(frame3);
    right.pushBack(frame4);

    auto loadingSprite = Protagonist::createWithSpriteFrame(frame1);

    auto animationRight = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

    loadingSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationRight)));

    this->addChild(loadingSprite, 0);

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    this->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));

    return true;
  }

  cocos2d::Layer* LoadingLayer::getLoadingLayer()
  {
    auto tmp = LoadingLayer::create();

    return tmp;
  }

}