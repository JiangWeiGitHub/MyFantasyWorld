#ifndef __Element_H__
#define __Element_H__

#include "../../../Global/Global.h"
#include "../Role.h"

namespace jiangweigithub {

  class Element: public Role
  {
  public:
    static Element* create();
    static Element* create(const std::string &filename);
    static Element* createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);

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

#endif // __Element_H__