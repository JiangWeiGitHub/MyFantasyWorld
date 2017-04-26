#include "./KeyRight.h"

KeyRight::KeyRight(KeyManager* keyManager)
{
  this->keyManager = keyManager;
}

KeyRight::~KeyRight()
{

}

void KeyRight::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_top == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressTop(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    // y += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    this->keyManager->setState(this->keyManager->getStateTop());
    this->keyManager->pressTop(sprite, x, y);

    return;
  }

  // y += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  this->keyManager->setState(this->keyManager->getStateTop());
  this->keyManager->pressTop(sprite, x, y);

  return;
}

void KeyRight::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_bottom == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressBottom(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    // y -= 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    this->keyManager->setState(this->keyManager->getStateBottom());
    this->keyManager->pressBottom(sprite, x, y);

    return;
  }

  // y -= 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  this->keyManager->setState(this->keyManager->getStateBottom());
  this->keyManager->pressBottom(sprite, x, y);

  return;
}

void KeyRight::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_left == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressLeft(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_right == true)
  {
    // x -= 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    this->keyManager->setState(this->keyManager->getStateLeft());
    this->keyManager->pressLeft(sprite, x, y);

    return;
  }

  // x -= 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  this->keyManager->setState(this->keyManager->getStateLeft());
  this->keyManager->pressLeft(sprite, x, y);
  
  return;
}

void KeyRight::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_right == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressRight(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true)
  {
    x += 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  x += 1;
  sprite->setPosition(cocos2d::Vec2(x, y));
  
  return;
}
