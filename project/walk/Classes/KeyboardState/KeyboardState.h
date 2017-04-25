#ifndef __KEYBOARDSTATE_H__
#define __KEYBOARDSTATE_H__

#include "iostream"
#include "cocos2d.h"

class KeyManager;

// top bottom left right stop -> five states

class KeyboardState
{
public:
  KeyboardState();
  virtual void pressTop(cocos2d::Sprite* sprite, float x, float y) {};
  virtual void pressBottom(cocos2d::Sprite* sprite, float x, float y) {};
  virtual void pressLeft(cocos2d::Sprite* sprite, float x, float y) {};
  virtual void pressRight(cocos2d::Sprite* sprite, float x, float y) {};

  bool obstacle_top, obstacle_bottom, obstacle_left, obstacle_right;

  void setState(KeyboardState* nextState);

private:  
  KeyboardState* state;
};

#endif // __KEYBOARDSTATE_H__
