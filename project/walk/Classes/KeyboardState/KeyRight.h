#ifndef __KEYRIGHT_H__
#define __KEYRIGHT_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"
#include "./KeyManager.h"
// #include "./KeyboardState.h"
// #include "./KeyTop.h"
// #include "./KeyBottom.h"
// #include "./KeyLeft.h"
// // #include "./KeyRight.h"
// #include "./KeyStop.h"

// class KeyTop;
// class KeyBottom;
// class KeyLeft;
// class KeyStop;
class KeyManager;
class KeyRight : public KeyboardState
{
public:
  KeyRight(KeyManager* keyManager);
  ~KeyRight();
  void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
  void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
  void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
  void pressRight(cocos2d::Sprite* sprite, float& x, float& y);
private:
  KeyManager* keyManager;
};

#endif // __KEYRIGHT_H__
