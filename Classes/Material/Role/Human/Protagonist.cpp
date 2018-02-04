#include "./Protagonist.h"

namespace jiangweigithub {

  // cocos2d::Sprite* Protagonist::getProtagonistSprite()
  // {
  //   cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");

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

  //   auto loadingSprite = cocos2d::Sprite::createWithSpriteFrame(frame1);

  //   auto animationRight = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

  //   loadingSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationRight)));

  //   return loadingSprite;
  // }

  Protagonist* Protagonist::create()
  {
    Protagonist *sprite = new Protagonist();
    if(sprite)
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  Protagonist* Protagonist::create(const std::string &filename)
  {
    Protagonist *sprite = new Protagonist();
    if(sprite && sprite->initWithFile(filename))
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  Protagonist* Protagonist::createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
  {
    Protagonist *sprite = new Protagonist();
    if(sprite && sprite->initWithSpriteFrame(spriteFrame))
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  bool Protagonist::setHeaddress(HEADDRESS stuff)
  {
    this->_headdress = stuff;

    return true;
  }

  HEADDRESS Protagonist::getHeaddress()
  {
    return this->_headdress;
  }

  bool Protagonist::setUpperBody(UPPER_BODY stuff)
  {
    this->_upperBody = stuff;

    return true;
  }

  UPPER_BODY Protagonist::getUpperBody()
  {
    return this->_upperBody;
  }

  bool Protagonist::setLowerBody(LOWER_BODY stuff)
  {
    this->_lowerBody = stuff;

    return true;
  }

  LOWER_BODY Protagonist::getLowerBody()
  {
    return this->_lowerBody;
  }

  bool Protagonist::setAccessory(ACCESSORY stuff)
  {
    this->_accessory = stuff;

    return true;
  }

  ACCESSORY Protagonist::getAccessory()
  {
    return this->_accessory;
  }

  bool Protagonist::setAvatar(std::string filePath)
  {
    this->_avatar = cocos2d::Sprite::create(filePath);

    return true;
  }

  cocos2d::Sprite* Protagonist::getAvatar()
  {
    return this->_avatar;
  }

}