#include "./Bird.h"

namespace jiangweigithub {

  bool Bird::setTalkContents(std::string contents)
  {
    this->_talkContents = contents;

    return true;
  }

  std::string Bird::getTalkContents()
  {
    return this->_talkContents;
  }

  bool Bird::setSex(SEX sex)
  {
    this->_sex = sex;

    return true;
  }

  SEX Bird::getSex()
  {
    return this->_sex;
  }

  bool Bird::setMood(MOOD mood)
  {
    this->_mood = mood;

    return true;
  }

  MOOD Bird::getMood()
  {
    return this->_mood;
  }

  bool Bird::setMovePosition(cocos2d::Point position)
  {
    (this->_position).x = position.x;
    (this->_position).y = position.y;

    return true;
  }

  cocos2d::Point Bird::getMovePosition()
  {
    return this->_position;
  }

}