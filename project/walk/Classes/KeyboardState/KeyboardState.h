#ifndef __KEYBOARDSTATE_H__
#define __KEYBOARDSTATE_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyManager.h"

// top bottom left right stop -> five states

class KeyManager;

class KeyboardState
{
public:
  KeyboardState();
  ~KeyboardState();
  virtual void pressTop() {};
  virtual void pressBottom() {};
  virtual void pressLeft() {};
  virtual void pressRight() {};

  void setKeyManager(KeyManager* keyManager);
  
  KeyManager* keyManager;

  bool obstacle_top, obstacle_bottom, obstacle_left, obstacle_right;
};

#endif // __KEYBOARDSTATE_H__
