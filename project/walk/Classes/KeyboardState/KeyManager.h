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

class KeyboardState;

class KeyManager
{
public:  
  KeyManager(KeyboardState* initState);
  KeyManager();
  ~KeyManager();
 
  void setState(KeyboardState* state);
  KeyboardState* getStateTop();
  KeyboardState* getStateBottom();
  KeyboardState* getStateLeft();
  KeyboardState* getStateRight();
  KeyboardState* getStateStop();

  void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
  void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
  void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
  void pressRight(cocos2d::Sprite* sprite, float& x, float& y);

private:  
  KeyboardState* _state;
  KeyboardState* _keyTop;
  KeyboardState* _keyBottom;
  KeyboardState* _keyLeft;
  KeyboardState* _keyRight;
  KeyboardState* _keyStop; 
};

#endif // __KEYMANAGER_H__
