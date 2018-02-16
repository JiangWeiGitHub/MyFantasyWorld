#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "../../../Global/Global.h"
#include "../Creature.h"

namespace jiangweigithub {

  class Human: public Creature
  {
  public:
    bool setTalkContents(std::string contents);
    std::string getTalkContents();

    bool setSex(SEX sex);
    SEX getSex();

    bool setMood(MOOD mood);
    MOOD getMood();

    bool setMovePosition(cocos2d::Point position);
    cocos2d::Point getMovePosition();

  private:
    std::string _talkContents;
    SEX _sex;
    MOOD _mood;
    cocos2d::Point _position;
  };
  
}

#endif // __HUMAN_H__