#ifndef __KEYMANAGER_H__
#define __KEYMANAGER_H__

#include "iostream"
#include "cocos2d.h"

class KeyManager : public KeyboardState
{
public:
  void createAllState();
  void pressBottom();
  void pressLeft();
  void pressRight();

private:
  KeyboardState* keyTop;
  KeyboardState* keyBottom;
  KeyboardState* keyLeft;
  KeyboardState* keyRight;
  KeyboardState* keyStop;
};

#endif // __KEYMANAGER_H__