#include "./Leader.h"

namespace jiangweigithub {

  unsigned int this->HP = 200;
  std::string this->heroName = "Baobao";
  std::string this->fileName = "sabin.png";

  cocos2d::Vector<cocos2d::SpriteFrame*> this->top;
  cocos2d::Vector<cocos2d::SpriteFrame*> this->bottom;
  cocos2d::Vector<cocos2d::SpriteFrame*> this->left;
  cocos2d::Vector<cocos2d::SpriteFrame*> this->right;

  cocos2d::Animation* this->animationTop;
  cocos2d::Animation* this->animationBottom;
  cocos2d::Animation* this->animationLeft;
  cocos2d::Animation* this->animationRight;

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
    this->HP = number;

    return true;
  }

  unsigned int Leader::getHP()
  {
    return this->HP;
  }

  bool Leader::setName(std::string name)
  {
    this->heroName = name;

    return true;
  }

  std::string Leader::getName()
  {
    return this->heroName;
  }

  cocos2d::Animation* Leader::getAnimationTop()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(330,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));

    this->top.pushBack(frame1);
    this->top.pushBack(frame2);
    this->top.pushBack(frame3);
    this->top.pushBack(frame4);

    this->animationTop = cocos2d::Animation::createWithSpriteFrames(this->top,0.2f);

    return this->animationTop;
  }

  cocos2d::Animation* Leader::getAnimationBottom()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(0,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(60,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));

    this->bottom.pushBack(frame1);
    this->bottom.pushBack(frame2);
    this->bottom.pushBack(frame3);
    this->bottom.pushBack(frame4);

    this->animationBottom = cocos2d::Animation::createWithSpriteFrames(this->bottom,0.2f);

    return this->animationBottom;
  }

  cocos2d::Animation* Leader::getAnimationLeft()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(90,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(150,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));

    this->left.pushBack(frame1);
    this->left.pushBack(frame2);
    this->left.pushBack(frame3);
    this->left.pushBack(frame4);

    this->animationLeft = cocos2d::Animation::createWithSpriteFrames(this->left,0.2f);

    return this->animationLeft;
  }

  cocos2d::Animation* Leader::getAnimationRight()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->fileName);

    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));

    this->right.pushBack(frame1);
    this->right.pushBack(frame2);
    this->right.pushBack(frame3);
    this->right.pushBack(frame4);

    this->animationRight = cocos2d::Animation::createWithSpriteFrames(this->right,0.2f);

    return this->animationRight;
  }
}