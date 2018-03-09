#include "./Leader.h"

namespace jiangweigithub {

  unsigned int Leader::HP = 200;
  std::string Leader::heroName = "Baobao";
  std::string Leader::fileName = "sabin.png";

  cocos2d::Vector<cocos2d::SpriteFrame*> Leader::top;
  cocos2d::Vector<cocos2d::SpriteFrame*> Leader::bottom;
  cocos2d::Vector<cocos2d::SpriteFrame*> Leader::left;
  cocos2d::Vector<cocos2d::SpriteFrame*> Leader::right;

  cocos2d::Animation* Leader::animationTop;
  cocos2d::Animation* Leader::animationBottom;
  cocos2d::Animation* Leader::animationLeft;
  cocos2d::Animation* Leader::animationRight;

  Leader* Leader::create()
  {
    Leader *sprite = new Leader();
    if(sprite)
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  Leader* Leader::create(const std::string &filename)
  {
    Leader *sprite = new Leader();
    if(sprite && sprite->initWithFile(filename))
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  Leader* Leader::createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
  {
    Leader *sprite = new Leader();
    if(sprite && sprite->initWithSpriteFrame(spriteFrame))
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

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
    Leader::heroName = name;

    return true;
  }

  std::string Leader::getName()
  {
    return Leader::heroName;
  }

  cocos2d::Animation* Leader::getAnimationTop()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(Leader::fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(330,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));

    Leader::top.pushBack(frame1);
    Leader::top.pushBack(frame2);
    Leader::top.pushBack(frame3);
    Leader::top.pushBack(frame4);

    Leader::animationTop = cocos2d::Animation::createWithSpriteFrames(Leader::top,0.2f);

    return Leader::animationTop;
  }

  cocos2d::Animation* Leader::getAnimationBottom()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(Leader::fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(0,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(60,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));

    Leader::bottom.pushBack(frame1);
    Leader::bottom.pushBack(frame2);
    Leader::bottom.pushBack(frame3);
    Leader::bottom.pushBack(frame4);

    Leader::animationBottom = cocos2d::Animation::createWithSpriteFrames(Leader::bottom,0.2f);

    return Leader::animationBottom;
  }

  cocos2d::Animation* Leader::getAnimationLeft()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(Leader::fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(90,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(150,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));

    Leader::left.pushBack(frame1);
    Leader::left.pushBack(frame2);
    Leader::left.pushBack(frame3);
    Leader::left.pushBack(frame4);

    Leader::animationLeft = cocos2d::Animation::createWithSpriteFrames(Leader::left,0.2f);

    return Leader::animationLeft;
  }

  cocos2d::Animation* Leader::getAnimationRight()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(Leader::fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));

    Leader::right.pushBack(frame1);
    Leader::right.pushBack(frame2);
    Leader::right.pushBack(frame3);
    Leader::right.pushBack(frame4);

    Leader::animationRight = cocos2d::Animation::createWithSpriteFrames(Leader::right,0.2f);

    return Leader::animationRight;
  }

}