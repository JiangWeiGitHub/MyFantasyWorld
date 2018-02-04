#include "./Human.h"

namespace jiangweigithub {

  Human* Human::create()
  {
    Human *sprite = new Human();
    if(sprite)
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  Human* Human::create(const std::string &filename)
  {
    Human *sprite = new Human();
    if(sprite && sprite->initWithFile(filename))
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  Human* Human::createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
  {
    Human *sprite = new Human();
    if(sprite && sprite->initWithSpriteFrame(spriteFrame))
    {
      sprite->autorelease();
      return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
  }

  bool Human::setTalkContents(std::string contents)
  {
    this->_talkContents = contents;

    return true;
  }

  std::string Human::getTalkContents()
  {
    return this->_talkContents;
  }

  bool Human::setSex(SEX sex)
  {
    this->_sex = sex;

    return true;
  }

  SEX Human::getSex()
  {
    return this->_sex;
  }

  bool Human::setMood(MOOD mood)
  {
    this->_mood = mood;

    return true;
  }

  MOOD Human::getMood()
  {
    return this->_mood;
  }

  bool Human::setMovePosition(cocos2d::Point position)
  {
    (this->_position).x = position.x;
    (this->_position).y = position.y;

    return true;
  }

  cocos2d::Point Human::getMovePosition()
  {
    return this->_position;
  }

}