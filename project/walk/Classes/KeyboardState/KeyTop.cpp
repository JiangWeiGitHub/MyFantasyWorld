#include "./KeyTop.h"

void KeyTop::pressTop(cocos2d::Sprite* sprite, float x, float y)
{
  if(obstacle_top == true)
  {
    setState(KeyManager::keyStop);

    return;
  }

  if(obstacle_bottom == true || obstacle_left == true || obstacle_right == true)
  {
    x += 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  x += 1;
  sprite->setPosition(cocos2d::Vec2(x, y));

  return;
}



void KeyTop::pressBottom(cocos2d::Sprite* sprite, float x, float y)
{
  if(obstacle_bottom == true)
  {
    setState(KeyManager::keyStop);

    return;
  }

  if(obstacle_top == true || obstacle_left == true || obstacle_right == true)
  {
    x -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  x -= 1;
  sprite->setPosition(cocos2d::Vec2(x, y));

  return;
}



void KeyTop::pressLeft(cocos2d::Sprite* sprite, float x, float y)
{
  if(obstacle_left == true)
  {
    setState(KeyManager::keyStop);

    return;
  }

  if(obstacle_top == true || obstacle_bottom == true || obstacle_right == true)
  {
    y -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  y -= 1;
  sprite->setPosition(cocos2d::Vec2(x, y));
  
  return;
}



void KeyTop::pressRight(cocos2d::Sprite* sprite, float x, float y)
{
  if(obstacle_right == true)
  {
    setState(KeyManager::keyStop);

    return;
  }

  if(obstacle_top == true || obstacle_bottom == true || obstacle_left == true)
  {
    y += 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  y += 1;
  sprite->setPosition(cocos2d::Vec2(x, y));
  
  return;
}
