#ifndef __Bird_H__
#define __Bird_H__

#include "../../../Global/Global.h"
#include "../Role.h"

namespace jiangweigithub {

  class Bird: public Role
  {
  public:
    static Bird* create();
    static Bird* create(const std::string &filename);
    static Bird* createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);

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

#endif // __Bird_H__