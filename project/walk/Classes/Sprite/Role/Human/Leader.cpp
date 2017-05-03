#include "./Leader.h"

namespace jiangweigithub {

  // Leader::Leader()
  // {
  //   this->HP = 200;
  //   this->name = "Baobao";

  //   this->createAnimation("sabin.png");
  // }

  // Leader::~Leader()
  // {
  //   this->HP = 200;
  //   this->name = "Baobao";
  // }

  Leader::HP = 200;
  Leader::name = "Baobao";
  Leader::animationTop = NULL;
  Leader::animationBottom = NULL;
  Leader::animationLeft = NULL;
  Leader::animationRight = NULL;

  bool Leader::setHP(unsigned int number)
  {
    Leader::HP = number;

    return true;
  }

  unsigned int Leader::getHP()
  {
    return Leader::HP;
  }

  bool Leader::setName(std::string name)
  {
    Leader::name = name;

    return true;
  }

  std::string Leader::getName()
  {
    return Leader::name;
  }

  cocos2d::Animation* Leader::getAnimationTop()
  {
    Leader::createAnimation("sabin.png");

    return Leader::animationTop;
  }

  cocos2d::Animation* Leader::getAnimationBottom()
  {
    Leader::createAnimation("sabin.png");

    return Leader::animationBottom;
  }

  cocos2d::Animation* Leader::getAnimationLeft()
  {
    Leader::createAnimation("sabin.png");

    return Leader::animationLeft;
  }

  cocos2d::Animation* Leader::getAnimationRight()
  {
    Leader::createAnimation("sabin.png");

    return Leader::animationRight;
  }

  bool Leader::createAnimation(std::string fileName)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(name);

    // top
    cocos2d::SpriteFrame* frame0 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(330,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));

    // bottom
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(0,0,30,50));
    cocos2d::SpriteFrame* frame5 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));
    cocos2d::SpriteFrame* frame6 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(60,0,30,50));
    cocos2d::SpriteFrame* frame7 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));

    // left
    cocos2d::SpriteFrame* frame8 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(90,0,30,50));
    cocos2d::SpriteFrame* frame9 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));
    cocos2d::SpriteFrame* frame10 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(150,0,30,50));
    cocos2d::SpriteFrame* frame11 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));

    // right
    cocos2d::SpriteFrame* frame12 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame13 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame14 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame15 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
      
    cocos2d::Vector<cocos2d::SpriteFrame*> top;
    top.pushBack(frame0);
    top.pushBack(frame1);
    top.pushBack(frame2);
    top.pushBack(frame3);

    cocos2d::Vector<cocos2d::SpriteFrame*> bottom;
    bottom.pushBack(frame4);
    bottom.pushBack(frame5);
    bottom.pushBack(frame6);
    bottom.pushBack(frame7);

    cocos2d::Vector<cocos2d::SpriteFrame*> left;
    left.pushBack(frame8);
    left.pushBack(frame9);
    left.pushBack(frame10);
    left.pushBack(frame11);

    cocos2d::Vector<cocos2d::SpriteFrame*> right;
    right.pushBack(frame12);
    right.pushBack(frame13);
    right.pushBack(frame14);
    right.pushBack(frame15);

    Leader::animationTop = cocos2d::Animation::createWithSpriteFrames(top,0.2f);
    Leader::animationBottom = cocos2d::Animation::createWithSpriteFrames(bottom,0.2f);
    Leader::animationLeft = cocos2d::Animation::createWithSpriteFrames(left,0.2f);
    Leader::animationRight = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

    return true;
  }

}