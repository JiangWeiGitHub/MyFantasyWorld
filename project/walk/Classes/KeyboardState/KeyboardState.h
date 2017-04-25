#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "iostream"
#include "cocos2d.h"

// top bottom left right stop -> five states

class KeyboardState
{
public:
  virtual void pressTop();
  virtual void pressBottom();
  virtual void pressLeft();
  virtual void pressRight();

private:
  static const int TOPWALK = 1;
  static const int BOTTOMWALK = 2;
  static const int LEFTWALK = 3;
  static const int RIGHTWALK = 4;
  static const int STOPWALK = 5;

  bool obstacle_top, _obstacle_bottom, _obstacle_left, _obstacle_right;

  virtual KeyboardState* setState(int nextState);
  int state;
};

class StopWalk : public KeyboardState
{
public:
  void pressTop();
  void pressBottom();
  void pressLeft();
  void pressRight();

private:
  KeyboardState* setState(int nextState);
};

#endif // __KEYBOARD_H__