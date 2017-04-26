#include "./KeyStop.h"

KeyStop::KeyStop(KeyManager* keyManager)
{
  this->keyManager = keyManager;
}

KeyStop::~KeyStop()
{

}

void KeyStop::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_top == true)
  {
    return;
  }

  if(KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    this->keyManager->setState(this->keyManager->getStateTop());
    this->keyManager->pressTop(sprite, x, y);

    return;
  }

  this->keyManager->setState(this->keyManager->getStateTop());
  this->keyManager->pressTop(sprite, x, y);

  return;
}

void KeyStop::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_bottom == true)
  {
    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    this->keyManager->setState(this->keyManager->getStateBottom());
    this->keyManager->pressBottom(sprite, x, y);

    return;
  }

  this->keyManager->setState(this->keyManager->getStateBottom());
  this->keyManager->pressBottom(sprite, x, y);

  return;
}

void KeyStop::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_left == true)
  {
    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_right == true)
  {
    this->keyManager->setState(this->keyManager->getStateLeft());
    this->keyManager->pressLeft(sprite, x, y);

    return;
  }

  this->keyManager->setState(this->keyManager->getStateLeft());
  this->keyManager->pressLeft(sprite, x, y);
  
  return;
}



void KeyStop::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_right == true)
  {
    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true)
  {
    this->keyManager->setState(this->keyManager->getStateRight());
    this->keyManager->pressRight(sprite, x, y);

    return;
  }

  this->keyManager->setState(this->keyManager->getStateRight());
  this->keyManager->pressRight(sprite, x, y);
  
  return;
}
