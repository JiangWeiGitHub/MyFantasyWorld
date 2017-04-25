#ifndef __KEYTOP_H__
#define __KEYTOP_H__

#include "iostream"
#include "cocos2d.h"

class KeyTop : public KeyboardState
{
public:
  void pressTop();
  void pressBottom();
  void pressLeft();
  void pressRight();

private:
  KeyboardState* setState(int nextState);
};

#endif // __KEYTOP_H__