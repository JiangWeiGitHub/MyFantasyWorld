#include "./KeyboardState.h"

KeyboardState::KeyboardState()
{
  obstacle_top =  obstacle_bottom = obstacle_left = obstacle_right = false;

  // rectangle = Rect(0,0,500,500);
  // rectangleZone = Vec2(0, 0); //init
}

void KeyboardState::setState(KeyboardState* nextState)
{
  this->state = nextState;
}