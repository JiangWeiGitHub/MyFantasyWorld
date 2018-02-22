#include "./Reptile.h"

namespace jiangweigithub {

  bool Reptile::setTalkContents(std::string contents)
  {
    this->_talkContents = contents;

    return true;
  }

  std::string Reptile::getTalkContents()
  {
    return this->_talkContents;
  }

  bool Reptile::setSex(SEX sex)
  {
    this->_sex = sex;

    return true;
  }

  SEX Reptile::getSex()
  {
    return this->_sex;
  }

  bool Reptile::setMood(MOOD mood)
  {
    this->_mood = mood;

    return true;
  }

  MOOD Reptile::getMood()
  {
    return this->_mood;
  }

  bool Reptile::setMovePosition(cocos2d::Point position)
  {
    (this->_position).x = position.x;
    (this->_position).y = position.y;

    return true;
  }

  cocos2d::Point Reptile::getMovePosition()
  {
    return this->_position;
  }

}