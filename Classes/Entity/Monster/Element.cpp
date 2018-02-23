#include "./Element.h"

namespace jiangweigithub {

  bool Element::setTalkContents(std::string contents)
  {
    this->_talkContents = contents;

    return true;
  }

  std::string Element::getTalkContents()
  {
    return this->_talkContents;
  }

  bool Element::setSex(SEX sex)
  {
    this->_sex = sex;

    return true;
  }

  SEX Element::getSex()
  {
    return this->_sex;
  }

  bool Element::setMood(MOOD mood)
  {
    this->_mood = mood;

    return true;
  }

  MOOD Element::getMood()
  {
    return this->_mood;
  }

  bool Element::setMovePosition(cocos2d::Point position)
  {
    (this->_position).x = position.x;
    (this->_position).y = position.y;

    return true;
  }

  cocos2d::Point Element::getMovePosition()
  {
    return this->_position;
  }

}