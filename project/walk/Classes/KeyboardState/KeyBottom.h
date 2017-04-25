#ifndef __KEYBOTTOM_H__
#define __KEYBOTTOM_H__

#include "iostream"
#include "cocos2d.h"

class KeyBottom : public KeyboardState
{
public:
  void pressTop();
  void pressBottom();
  void pressLeft();
  void pressRight();

private:
  KeyboardState* setState(int nextState);
};

#endif // __KEYBOTTOM_H__