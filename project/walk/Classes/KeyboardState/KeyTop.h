#ifndef __KEYTOP_H__
#define __KEYTOP_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"
#include "./KeyManager.h"

// #include "./KeyboardState.h"
// #include "./KeyTop.h"
// #include "./KeyBottom.h"
// #include "./KeyLeft.h"
// #include "./KeyRight.h"
// #include "./KeyStop.h"

class KeyManager;

class KeyTop : public KeyboardState
{
public:
  KeyTop(KeyManager* keyManager);
  ~KeyTop();
  void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
  void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
  void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
  void pressRight(cocos2d::Sprite* sprite, float& x, float& y);
private:
  KeyManager* keyManager;
};

#endif // __KEYTOP_H__
