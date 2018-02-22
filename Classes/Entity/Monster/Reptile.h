#ifndef __Reptile_H__
#define __Reptile_H__

#include "../../../Global/Global.h"
#include "../Role.h"

namespace jiangweigithub {

  class Reptile: public Role
  {
  public:
    static Reptile* create();
    static Reptile* create(const std::string &filename);
    static Reptile* createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);

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

#endif // __Reptile_H__