#include "./KeyTop.h"

void KeyTop::pressTop()
{
  if(obstacle_top == true)
  {
    setState(STOPWALK);

    return;
  }

  if(obstacle_bottom == true || obstacle_left == true || obstacle_right == true)
  {
    this->_xxx += 1;
    sprite->setPosition(Vec2(this->_xxx, this->_yyy));

    return;
  }

  this->_xxx += 1;
  sprite->setPosition(Vec2(this->_xxx, this->_yyy));
  
  return;
}



void KeyTop::pressBottom()
{
  if(obstacle_bottom == true)
  {
    setState(STOPWALK);

    return;
  }

  if(obstacle_top == true || obstacle_left == true || obstacle_right == true)
  {
    this->_xxx -= 1;
    sprite->setPosition(Vec2(this->_xxx, this->_yyy));

    return;
  }

  this->_xxx -= 1;
  sprite->setPosition(Vec2(this->_xxx, this->_yyy));
  
  return;
}



void KeyTop::pressLeft()
{
  if(obstacle_left == true)
  {
    setState(STOPWALK);

    return;
  }

  if(obstacle_top == true || obstacle_bottom == true || obstacle_right == true)
  {
    this->_yyy -= 1;
    sprite->setPosition(Vec2(this->_xxx, this->_yyy));

    return;
  }

  this->_yyy -= 1;
  sprite->setPosition(Vec2(this->_xxx, this->_yyy));
  
  return;
}



void KeyTop::pressRight()
{
  if(obstacle_right == true)
  {
    setState(STOPWALK);

    return;
  }

  if(obstacle_top == true || obstacle_bottom == true || obstacle_left == true)
  {
    this->_yyy += 1;
    sprite->setPosition(Vec2(this->_xxx, this->_yyy));

    return;
  }

  this->_yyy += 1;
  sprite->setPosition(Vec2(this->_xxx, this->_yyy));
  
  return;
}