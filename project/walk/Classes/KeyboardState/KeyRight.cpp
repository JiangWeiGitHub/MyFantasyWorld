#include "./KeyRight.h"

void KeyRight::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(obstacle_top == true)
  {
    KeyboardState::setState(new KeyStop());

    return;
  }

  if(obstacle_bottom == true || obstacle_left == true || obstacle_right == true)
  {
    y += 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  y += 1;
  sprite->setPosition(cocos2d::Vec2(x, y));

  return;
}



void KeyRight::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(obstacle_bottom == true)
  {
    KeyboardState::setState(new KeyStop());

    return;
  }

  if(obstacle_top == true || obstacle_left == true || obstacle_right == true)
  {
    y -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  y -= 1;
  sprite->setPosition(cocos2d::Vec2(x, y));

  return;
}



void KeyRight::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(obstacle_left == true)
  {
    KeyboardState::setState(new KeyStop());

    return;
  }

  if(obstacle_top == true || obstacle_bottom == true || obstacle_right == true)
  {
    x -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  x -= 1;
  sprite->setPosition(cocos2d::Vec2(x, y));
  
  return;
}



void KeyRight::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(obstacle_right == true)
  {
    KeyboardState::setState(new KeyStop());

    return;
  }

  if(obstacle_top == true || obstacle_bottom == true || obstacle_left == true)
  {
    x += 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  x += 1;
  sprite->setPosition(cocos2d::Vec2(x, y));
  
  return;
}
