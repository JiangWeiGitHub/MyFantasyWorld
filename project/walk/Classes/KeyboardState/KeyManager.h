#ifndef __KEYMANAGER_H__
#define __KEYMANAGER_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"

class KeyboardState;

class KeyManager
{
public:  
  // KeyManager(KeyboardState* initState);
  KeyManager();
  ~KeyManager();
 
  void setState(KeyboardState* state);
  KeyboardState* getState();

  void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
  void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
  void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
  void pressRight(cocos2d::Sprite* sprite, float& x, float& y);

private:  
  KeyboardState* _state; 
};

#endif // __KEYMANAGER_H__
