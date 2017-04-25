#include "./keyBoard.h"

void StopWalk::pressTop()
{
  if(obstacle_top == true)
  {
    return;
  }

  this->_xxx += 1;
  sprite->setPosition(Vec2(this->_xxx, this->_yyy));
  return;
}