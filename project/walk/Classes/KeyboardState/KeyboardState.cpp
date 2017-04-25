#include "./KeyboardState.h"

KeyboardState::KeyboardState()
{
  obstacle_top =  obstacle_bottom = obstacle_left = obstacle_right = false;
}

void KeyboardState::setState(KeyboardState* nextState)
{
  this->state = nextState;
}