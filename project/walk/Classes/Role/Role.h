#ifndef __ROLE_H__
#define __ROLE_H__

#include "iostream"
#include "cocos2d.h"

class Role : public cocos2d::Sprite
{
public:
  Role();
  ~Role();
  void setName(std::string name);
  std::string getName(void);
    
  // // implement the "static create()" method manually
  // CREATE_FUNC(Role);

private:
  std::string _name;
};

#endif // __ROLE_H__