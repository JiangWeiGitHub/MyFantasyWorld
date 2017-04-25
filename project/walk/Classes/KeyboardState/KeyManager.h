#ifndef __KEYMANAGER_H__
#define __KEYMANAGER_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"

#include "./KeyTop.h"
#include "./KeyBottom.h"
#include "./KeyLeft.h"
#include "./KeyRight.h"
#include "./KeyStop.h"

class KeyTop;
class KeyBottom;
class KeyLeft;
class KeyRight;
class KeyStop;

class KeyManager : public KeyboardState
{
public:
  KeyManager();
  void setInitState(KeyboardState* initState);
  void pressTop(cocos2d::Sprite* sprite, float x, float y);
  void pressBottom(cocos2d::Sprite* sprite, float x, float y);
  void pressLeft(cocos2d::Sprite* sprite, float x, float y);
  void pressRight(cocos2d::Sprite* sprite, float x, float y);

  static KeyTop* keyTop;
  static KeyBottom* keyBottom;
  static KeyLeft* keyLeft;
  static KeyRight* keyRight;
  static KeyStop* keyStop;

private:
  KeyboardState* state;
};

#endif // __KEYMANAGER_H__
