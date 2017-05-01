#include "./LoadingTitleSprite.h"

namespace jiangweigithub {

  // LoadingTitleSprite::LoadingTitleSprite()
  // {
  //   loadingSprite = NULL;
  //   loadingTitle = NULL;
  //   createTitle("Loading...");
  //   createLoadingSprite();
  // }

  // LoadingTitleSprite::~LoadingTitleSprite()
  // {
  //   delete loadingTitle;
  //   delete loadingSprite;
  // }

  cocos2d::Label* LoadingTitleSprite::getLoadingTitle()
  {
    auto name = "Loading";
    auto tmp = cocos2d::Label::createWithTTF(name, "fonts/arial.ttf", 24);
    tmp->enableBold();
    tmp->setAdditionalKerning(1);

    return tmp;
  }

  // cocos2d::Sprite* LoadingTitleSprite::getLoadingSprite()
  // {
  //   LoadingSprite::create();

  //   return loadingSprite;
  // }

  bool LoadingTitleSprite::init()
  {
    // auto name = "Loading";
    // if ( !Label::createWithTTF(name, "fonts/arial.ttf", 24) )
    // {
    //   return false;
    // }

    // this->enableBold();
    // this->setAdditionalKerning(1);

    return true;
  }

  bool LoadingTitleSprite::createTitle(std::string name)
  {
    auto loadingTitle = cocos2d::Label::createWithTTF(name, "fonts/arial.ttf", 24);
    loadingTitle->enableBold();
    loadingTitle->setAdditionalKerning(1);
  }

  // bool LoadingTitleSprite::createLoadingSprite()
  // {
  //   cocos2d::Texture2D* textTure = cocos2d::TextureCache::getInstance()->addImage("sabin.png");

  //   // right
  //   cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
  //   cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
  //   cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
  //   cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));

  //   cocos2d::Vector<cocos2d::SpriteFrame*> right;
  //   right.pushBack(frame1);
  //   right.pushBack(frame2);
  //   right.pushBack(frame3);
  //   right.pushBack(frame4);

  //   loadingSprite = cocos2d::Sprite::createWithSpriteFrame(frame1);
  //   auto animationRight = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

  //   loadingSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationRight)));
  // }
}